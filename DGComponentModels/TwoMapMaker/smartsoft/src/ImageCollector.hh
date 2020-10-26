//--------------------------------------------------------------------------
// Code generated by the SmartSoft MDSD Toolchain
// The SmartSoft Toolchain has been developed by:
//  
// Service Robotics Research Center
// University of Applied Sciences Ulm
// Prittwitzstr. 10
// 89075 Ulm (Germany)
//
// Information about the SmartSoft MDSD Toolchain is available at:
// www.servicerobotik-ulm.de
//
// This file is generated once. Modify this file to your needs. 
// If you want the toolchain to re-generate this file, please 
// delete it before running the code generator.
//--------------------------------------------------------------------------
#ifndef _IMAGECOLLECTOR_HH
#define _IMAGECOLLECTOR_HH

#include "ImageCollectorCore.hh"

class ImageCollector  : public ImageCollectorCore
{
private:
public:
	ImageCollector(SmartACE::SmartComponent *comp);
	virtual ~ImageCollector();
	
	virtual int on_entry();
	virtual int on_execute();
	virtual int on_exit();
};

#endif
