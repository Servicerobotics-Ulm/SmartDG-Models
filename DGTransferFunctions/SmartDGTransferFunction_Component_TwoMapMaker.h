//================================================================
//
//  Copyright (c) 2020 Technische Hochschule Ulm, Servicerobotics Ulm, Germany
//
//        Servicerobotik Ulm 
//        Christian Schlegel
//        Ulm University of Applied Sciences
//        Prittwitzstr. 10
//        89075 Ulm
//        Germany
//
//	  http://www.servicerobotik-ulm.de/
//
//  This file is part of the SmartDG Dependency Graph extension for SmartMDSD Toolchain.
//
//  Contributors:
//	Vineet Nagrath	   :	Vineet.Nagrath@thu.de
//	Alex Lotz	   	   :	Alex.Lotz@thu.de
//	Christian Schlegel :	Christian.Schlegel@thu.de
//
//  Licence:
//
//  BSD 3-Clause License
//  
//  Copyright (c) 2019, Servicerobotics Ulm
//  All rights reserved.
//  
//  Redistribution and use in source and binary forms, with or without
//  modification, are permitted provided that the following conditions are met:
//  
//  * Redistributions of source code must retain the above copyright notice, this
//    list of conditions and the following disclaimer.
//  
//  * Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.
//  
//  * Neither the name of the copyright holder nor the names of its
//    contributors may be used to endorse or promote products derived from
//    this software without specific prior written permission.
//  
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
//  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
//  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
//  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
//  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
//  DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
//  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
//  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
//  OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
//  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//  https://opensource.org/licenses/BSD-3-Clause
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

