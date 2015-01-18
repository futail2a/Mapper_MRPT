// -*-C++-*-
/*!
 * @file  MobileRobotSVC_impl.cpp
 * @brief Service implementation code of MobileRobot.idl
 *
 */

#include "MobileRobotSVC_impl.h"

#include "Mapper_MRPT.h"
/*
 * Example implementational code for IDL interface RTC::OGMapper
 */
OGMapperSVC_impl::OGMapperSVC_impl()
{
  // Please add extra constructor code here.
}


OGMapperSVC_impl::~OGMapperSVC_impl()
{
  // Please add extra destructor code here.
}


/*
 * Methods corresponding to IDL attributes and operations
 */
RTC::RETURN_VALUE OGMapperSVC_impl::initializeMap(const RTC::OGMapConfig& config, const RTC::Pose2D& initialPose)
{
	RTC::RETURN_VALUE result;
  // Please insert your code here and remove the following warning pragma
#ifndef WIN32
  #warning "Code missing in function <RTC::RETURN_VALUE OGMapperSVC_impl::initializeMap(const RTC::OGMapConfig& config, const RTC::Pose2D& initialPose)>"
#endif
  return result;
}

RTC::RETURN_VALUE OGMapperSVC_impl::startMapping()
{
	RTC::RETURN_VALUE result = RETVAL_OK;
	if(m_pRTC->startMapping() < 0) {
		return RETVAL_INVALID_PRECONDITION;
	}
  return result;
}

RTC::RETURN_VALUE OGMapperSVC_impl::stopMapping()
{
	RTC::RETURN_VALUE result = RETVAL_OK;
	if(m_pRTC->stopMapping() < 0) {
		return RETVAL_INVALID_PRECONDITION;
	}
	return result;
}

RTC::RETURN_VALUE OGMapperSVC_impl::suspendMapping()
{
	RTC::RETURN_VALUE result;
  // Please insert your code here and remove the following warning pragma
#ifndef WIN32
  #warning "Code missing in function <RTC::RETURN_VALUE OGMapperSVC_impl::suspendMapping()>"
#endif
  return result;
}

RTC::RETURN_VALUE OGMapperSVC_impl::resumeMapping()
{
	RTC::RETURN_VALUE result;
  // Please insert your code here and remove the following warning pragma
#ifndef WIN32
  #warning "Code missing in function <RTC::RETURN_VALUE OGMapperSVC_impl::resumeMapping()>"
#endif
  return result;
}

RTC::RETURN_VALUE OGMapperSVC_impl::getState(RTC::MAPPER_STATE& state)
{
  RTC::RETURN_VALUE result = RETVAL_OK;
  state = m_pRTC->getState();
  return result;
}

RTC::RETURN_VALUE OGMapperSVC_impl::requestCurrentBuiltMap(RTC::OGMap_out map)
{
	RTC::RETURN_VALUE result = RETVAL_OK;
	m_pRTC->getCurrentMap(map);

	if(m_pRTC->getMode() == MODE_ODOMETRY_TIME_OUT){
		result = RETVAL_ODOMETRY_TIME_OUT;
		return result;
	}else if(m_pRTC->getMode() == MODE_RANGE_TIME_OUT){
		result = RETVAL_RANGE_TIME_OUT;
		return result;
	}else if(m_pRTC->getMode() == MODE_ODOMETRY_INVALID_VALUE){
		result = RETVAL_ODOMETRY_INVALID_VALUE;
		return result;
	}

	return result;
}



// End of example implementational code



