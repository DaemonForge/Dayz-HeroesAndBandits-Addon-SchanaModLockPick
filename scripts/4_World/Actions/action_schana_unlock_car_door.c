/*
This needs to be added to the "Actions" array in the config.json under the "HeroesAndBandits" folder in the server profile
This can also be done by creating a modded class for the HeroesAndBanditsConfig and adding an addaction after super
  {
	"Name": "CarRaid",    Must Match the Action Specifed in the NewPlayerAction
	"Affinity": "bandit", Specifies if it will remove or add Humanity hero adds, bandit subtracts, bambi means no change 
	"Humanity": 200,      How much humanity to modify their exsiting humanity
	"NotifiyPlayer": 1    Wether it should Notifiy the Player how much humanity has changed
  }

Some Safe Helper Functions are

GetHeroesAndBandits().NewPlayerAction(PlayerID, ActionName) //Adds an action to the player, adding an action to the player will update the stat, update the players humanity, action must exsit in the config or it will consider the action to give 0 humanity
GetHeroesAndBandits().GetPlayerAffinity(PlayerID) //This will return the players Affinity in a string Ussaly bambi, hero, bandit but this can be configured by the server admins will return bambi(Default Level Affinity) if the player can't be found
GetHeroesAndBandits().GetPlayerHumanity(PlayerID) //This will return the players Humanity in a float value, it will return 0 if the player can't be found
GetHeroesAndBandits().GetPlayerLevel(PlayerID) //Returns the HabLevel object will return the default level if player can't be found
GetHeroesAndBandits().GetPlayerLevelName(PlayerID) //Returns the HabLevel Name in a string it will the default level's name usally Bambi if the player can't be found
GetHeroesAndBandits().GetPlayerStat(PlayerID, StatName) //Returns INT of the player stat, if player or the player's stat doesn't exist it returns 0

*/

modded class ActionSchanaUnlockCarDoor
{
   override void OnFinishProgressServer(ActionData action_data)
    {
		super.OnFinishProgressServer(action_data); //Call Super
		
		PlayerBase sourcePlayer = PlayerBase.Cast(action_data.m_Player); //Get the Source Player
		string sourcePlayerID = sourcePlayer.GetIdentity().GetPlainId(); //Get the Source Player 64 ID
		
        CarScript carScript = CarScript.Cast(action_data.m_Target.GetParent()); //Gets the Car
		
        if (carScript) //Check if car is valid
        {
            string ownerPlayer = carScript.m_Trader_LastDriverId;
            if (!carScript.m_Trader_Locked) //Check if the car is not locked any more to ensure it was a successfull raid before providing the Humanity
            {
				if ( ownerPlayer != sourcePlayerID) //If owner is raider don't count as a raid
				{
					//Adds Action to the player via their Steam64ID and will adjust Humanity Acordingly as well as notify the player
					GetHeroesAndBandits().NewPlayerAction(sourcePlayerID, "CarRaid"); 
				}
            }
        }
    }
}