#!/bin/bash
#
# This script is run prior to deployment of component Cam2
# The working directory of this script is the deployment project folder.
#

#--------------------------------------------------------------------------
# Code generated by the SmartSoft MDSD Toolchain
# The SmartSoft Toolchain has been developed by:
#  
# Service Robotics Research Center
# University of Applied Sciences Ulm
# Prittwitzstr. 10
# 89075 Ulm (Germany)
#
# Information about the SmartSoft MDSD Toolchain is available at:
# www.servicerobotik-ulm.de
#
# This file is generated once. Modify this file to your needs. 
# If you want the toolchain to re-generate this file, please 
# delete it before running the code generator.
#--------------------------------------------------------------------------

# uncomment to enable predeploy script delivered by component
source $REFERENCED_PROJECT_ZeroCamera/smartsoft/src/predeploy.sh

# Add SmartSoft libraries that shall be deployed to the target device where this
# component is to be deployed.
# These libraries will be searched in $SMART_ROOT/lib and then deployed
# Add one file per line.
#DEPLOY_LIBRARIES="$DEPLOY_LIBRARIES
#libSmartSickInterface.so
#"


# add custom code here. E.g. use this script to collect data-files and 
# copy them to src/<COMPONENT>_data, etc.

