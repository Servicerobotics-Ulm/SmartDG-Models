//============================================================================
// File Name        : SmartDGTransferFunction_Component_TwoMapMaker.h
//
//  Copyright (C) 2017 Vineet Nagrath, Alex Lotz
//
//        nagrath@hs-ulm.de		
//        lotz@hs-ulm.de
//
//        Servicerobotik Ulm
//        Christian Schlegel
//        Ulm University of Applied Sciences
//        Prittwitzstr. 10
//        89075 Ulm
//        Germany
//
//  This file is part of the SmartMDSD Toolchain V3. 
//
//================================================================
#ifndef SMARTDGTRANSFERFUNCTION_COMPONENT_TWOMAPMAKER_H_
#define SMARTDGTRANSFERFUNCTION_COMPONENT_TWOMAPMAKER_H_
#include <SmartDG.h>

namespace SmartDG	{
namespace TransferFunction_Component_TwoMapMaker{

	bool Get(vector< vector<SmartDG::DependencyPort> >& DP, string IO, string Port, string Obj)	{
		unsigned int i = 0;
		if (IO == "In") i = 0;
		if (IO == "Out") i = 1;
		for(unsigned int j = 0; j< DP[i].size(); j++)	{
			if ( DP[i][j].Name == Port)	{
				for(unsigned int k = 0; k< DP[i][j].DO.size(); k++)	{
					if (DP[i][j].DO[k].Name == Obj)
						return DP[i][j].DO[k].Get().b;
				}
			}
		}
	}

	bool Set(vector< vector<SmartDG::DependencyPort> >& DP, string IO, string Port, string Obj, bool val)	{
		unsigned int i = 0;
		if (IO == "In") i = 0;
		if (IO == "Out") i = 1;
		for(unsigned int j = 0; j< DP[i].size(); j++)	{
			if ( DP[i][j].Name == Port)	{
				for(unsigned int k = 0; k< DP[i][j].DO.size(); k++)	{
					if (DP[i][j].DO[k].Name == Obj)	{
						DependencyDataPackage ddp;
						ddp.b = val;
						DP[i][j].DO[k].Set(ddp);
					}
				}
			}
		}
	}


	inline string Name()	{
		if(SmartDG_TFV) cout << "Name" << endl;cout << "Name" << endl;
		return "TwoMapMaker";
	}

	inline void TF(vector<string> &Return, vector< vector<SmartDG::DependencyPort> >& DP)	{
		cout << "TransferFunction_Component_TwoMapMaker::TF" << endl;
		bool In_Image1_DGPrivacy_All = Get(DP,"In","Image1","DGPrivacy");
		bool In_Image2_DGPrivacy_All = Get(DP,"In","Image2","DGPrivacy");
		bool In_GrayImage1_DGPrivacy_All = Get(DP,"In","GrayImage1","DGPrivacy");
		bool In_GrayImage2_DGPrivacy_All = Get(DP,"In","GrayImage2","DGPrivacy");

		cout << "In.Image1.DGPrivacy.All : " << In_Image1_DGPrivacy_All << endl;
		cout << "In.Image2.DGPrivacy.All : " << In_Image2_DGPrivacy_All << endl;
		cout << "In.GrayImage1.DGPrivacy.All : " << In_GrayImage1_DGPrivacy_All << endl;
		cout << "In.GrayImage2.DGPrivacy.All : " << In_GrayImage2_DGPrivacy_All << endl;

		Set(DP,"Out","RGBMap","DGPrivacy", In_Image1_DGPrivacy_All && In_Image2_DGPrivacy_All);
		Set(DP,"Out","GrayMap","DGPrivacy", In_GrayImage1_DGPrivacy_All && In_GrayImage2_DGPrivacy_All);
		Return.push_back(SmartDG_OK);
	}

	inline void FT(vector<string> &Return, vector< vector<SmartDG::DependencyPort> >& DP)	{
		cout << "TransferFunction_Component_TwoMapMaker::FT" << endl;
		bool Out_RGBMap_DGPrivacy_All = Get(DP,"Out","RGBMap","DGPrivacy");
		bool Out_GrayMap_DGPrivacy_All = Get(DP,"Out","GrayMap","DGPrivacy");

		cout << "Out.RGBMap.DGPrivacy.All : " << Out_RGBMap_DGPrivacy_All << endl;
		cout << "Out.GrayMap.DGPrivacy.All : " << Out_GrayMap_DGPrivacy_All << endl;

		Set(DP,"In","Image1","DGPrivacy", Out_RGBMap_DGPrivacy_All);
		Set(DP,"In","Image2","DGPrivacy", Out_RGBMap_DGPrivacy_All);
		Set(DP,"In","GrayImage1","DGPrivacy", Out_GrayMap_DGPrivacy_All);
		Set(DP,"In","GrayImage2","DGPrivacy", Out_GrayMap_DGPrivacy_All);

		Return.push_back(SmartDG_OK);
	}

	inline void TFT(string Fun, vector<string> &Return, vector< vector<SmartDG::DependencyPort> >& DP)	{
		if(SmartDG_TFV) cout << "Name" << endl;cout << "TransferFunction_Component_TwoMapMaker" <<
				"SmartComponent " << Name() << " " << Fun  << endl;
		if(Fun == "List")	{
			Return.push_back(SmartDG_OK);
			Return.push_back("List");
			Return.push_back("Name");
			Return.push_back("TF");
			Return.push_back("FT");
			return;
		}
		if(Fun == "Name")	{
			Return.push_back(SmartDG_OK);
			Return.push_back(Name());
			return;
		}
		if(Fun == "TF")	{ TF(Return, DP);	return;	}
		if(Fun == "FT")	{ FT(Return, DP);	return;	}

		Return.push_back(SmartDG_NOT_OK); // Function Not Found
		return;
	}
} /* namespace TransferFunction_Component_TwoMapMaker */
} /* namespace SmartDG */
#endif /* SMARTDGTRANSFERFUNCTION_COMPONENT_TWOMAPMAKER_H_ */

