class CfgPatches
{
	class HeroesAndBanitsSMLP
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]={
			"RPC_Scripts",
			"DZ_Scripts",
			"DZ_Data",
			"HeroesAndBandits",
			"SchanaModLockPick"
		};
	};
};

class CfgMods
{
	class HeroesAndBanitsSMLP
	{
		dir="HeroesAndBanitsSMLP";
        picture="";
        action="";
        hideName=1;
        hidePicture=1;
        name="HeroesAndBanitsSMLP";
        credits="DaemonForge";
        author="DaemonForge";
        authorID="0";
        version="0.1";
        extra=0;
        type="mod";
	    dependencies[]={ "World" };
	    class defs
	    {
			class worldScriptModule
            {
                value="";
                files[]={ "HeroesAndBanitsSMLP/scripts/4_World" };
            };
        };
    };
};
