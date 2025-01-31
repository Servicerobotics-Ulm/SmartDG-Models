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
// Please do not modify this file. It will be re-generated
// running the code generator.
//--------------------------------------------------------------------------
#include "DGService_DGBasicLink/DGBasicLinkObjectACE.hh"
#include <ace/SString.h>

// serialization operator for element DGBasicLinkObject
ACE_CDR::Boolean operator<<(ACE_OutputCDR &cdr, const DGService_DGBasicLinkIDL::DGBasicLinkObject &data)
{
	ACE_CDR::Boolean good_bit = true;
	// serialize list-element name
	good_bit = good_bit && cdr << ACE_CString(data.name.c_str());
	
	return good_bit;
}

// de-serialization operator for element DGBasicLinkObject
ACE_CDR::Boolean operator>>(ACE_InputCDR &cdr, DGService_DGBasicLinkIDL::DGBasicLinkObject &data)
{
	ACE_CDR::Boolean good_bit = true;
	// deserialize string-type element name
	ACE_CString data_name_str;
	good_bit = good_bit && cdr >> data_name_str;
	data.name = data_name_str.c_str();
	
	return good_bit;
}

// serialization operator for CommunicationObject DGBasicLinkObject
ACE_CDR::Boolean operator<<(ACE_OutputCDR &cdr, const DGService_DGBasicLink::DGBasicLinkObject &obj)
{
	return cdr << obj.get();
}

// de-serialization operator for CommunicationObject DGBasicLinkObject
ACE_CDR::Boolean operator>>(ACE_InputCDR &cdr, DGService_DGBasicLink::DGBasicLinkObject &obj)
{
	return cdr >> obj.set();
}
