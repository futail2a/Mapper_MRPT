// -*- C++ -*-
/*!
 * @file  Mapper_MRPT.h
 * @brief Mapper RTC using MRPT
 * @date  $Date$
 *
 * $Id$
 */

#ifndef MAPPER_MRPT_H
#define MAPPER_MRPT_H

#include <rtm/idl/BasicDataTypeSkel.h>
#include <rtm/idl/ExtendedDataTypesSkel.h>
#include <rtm/idl/InterfaceDataTypesSkel.h>

#include <rtm/Manager.h>
#include <rtm/DataFlowComponentBase.h>
#include <rtm/CorbaPort.h>
#include <rtm/DataInPort.h>
#include <rtm/DataOutPort.h>

// Service implementation headers
// <rtc-template block="service_impl_h">
#include "MobileRobotSVC_impl.h"

// </rtc-template>

// Service Consumer stub headers
// <rtc-template block="consumer_stub_h">

// </rtc-template>



#include "MapBuilder.h"
using namespace RTC;

enum MAPPER_MRPT_MODE{
	MODE_NORMAL,
	MODE_RANGE_TIME_OUT,
	MODE_RANGE_INVALID_VALUE,
	MODE_ODOMETRY_TIME_OUT,
	MODE_ODOMETRY_INVALID_VALUE
};

/*!
 * @class Mapper_MRPT
 * @brief Mapper RTC using MRPT
 *
 */
class Mapper_MRPT
  : public RTC::DataFlowComponentBase
{
 public:
  /*!
   * @brief constructor
   * @param manager Maneger Object
   */
  Mapper_MRPT(RTC::Manager* manager);

  /*!
   * @brief destructor
   */
  ~Mapper_MRPT();

  // <rtc-template block="public_attribute">
  
  // </rtc-template>

  // <rtc-template block="public_operation">
  
  // </rtc-template>

  /***
   *
   * The initialize action (on CREATED->ALIVE transition)
   * formaer rtc_init_entry() 
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
   virtual RTC::ReturnCode_t onInitialize();

  /***
   *
   * The finalize action (on ALIVE->END transition)
   * formaer rtc_exiting_entry()
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onFinalize();

  /***
   *
   * The startup action when ExecutionContext startup
   * former rtc_starting_entry()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onStartup(RTC::UniqueId ec_id);

  /***
   *
   * The shutdown action when ExecutionContext stop
   * former rtc_stopping_entry()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onShutdown(RTC::UniqueId ec_id);

  /***
   *
   * The activated action (Active state entry action)
   * former rtc_active_entry()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
   virtual RTC::ReturnCode_t onActivated(RTC::UniqueId ec_id);

  /***
   *
   * The deactivated action (Active state exit action)
   * former rtc_active_exit()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
   virtual RTC::ReturnCode_t onDeactivated(RTC::UniqueId ec_id);

  /***
   *
   * The execution action that is invoked periodically
   * former rtc_active_do()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
   virtual RTC::ReturnCode_t onExecute(RTC::UniqueId ec_id);

  /***
   *
   * The aborting action when main logic error occurred.
   * former rtc_aborting_entry()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onAborting(RTC::UniqueId ec_id);

  /***
   *
   * The error action in ERROR state
   * former rtc_error_do()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onError(RTC::UniqueId ec_id);

  /***
   *
   * The reset action that is invoked resetting
   * This is same but different the former rtc_init_entry()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
   virtual RTC::ReturnCode_t onReset(RTC::UniqueId ec_id);
  
  /***
   *
   * The state update action that is invoked after onExecute() action
   * no corresponding operation exists in OpenRTm-aist-0.2.0
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onStateUpdate(RTC::UniqueId ec_id);

  /***
   *
   * The action that is invoked when execution context's rate is changed
   * no corresponding operation exists in OpenRTm-aist-0.2.0
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onRateChanged(RTC::UniqueId ec_id);


 protected:
  // <rtc-template block="protected_attribute">
  
  // </rtc-template>

  // <rtc-template block="protected_operation">
  
  // </rtc-template>

  // Configuration variable declaration
  // <rtc-template block="config_declare">
  /*!
   * 
   * - Name:  debug
   * - DefaultValue: 0
   */
  int m_debug;
  /*!
   * 
   * - Name:  start_map_update_in_activated
   * - DefaultValue: false
   */
  std::string m_start_map_update_in_activated;
  /*!
   * 
   * - Name:  x_min
   * - DefaultValue: -10.0
   */
  double m_x_min;
  /*!
   * 
   * - Name:  x_max
   * - DefaultValue: 10.0
   */
  double m_x_max;
  /*!
   * 
   * - Name:  y_min
   * - DefaultValue: -10.0
   */
  double m_y_min;
  /*!
   * 
   * - Name:  y_max
   * - DefaultValue: 10.0
   */
  double m_y_max;
  /*!
   * 
   * - Name:  resolution
   * - DefaultValue: 0.05
   */
  double m_resolution;
  /*!
   * 
   * - Name:  init_pose_x
   * - DefaultValue: 0.0
   */
  double m_init_pose_x;
  /*!
   * 
   * - Name:  init_pose_y
   * - DefaultValue: 0.0
   */
  double m_init_pose_y;
  /*!
   * 
   * - Name:  init_pose_th
   * - DefaultValue: 0.0
   */
  double m_init_pose_th;
  /*!
   * 
   * - Name:  log_dir
   * - DefaultValue: log_out
   */
  std::string m_log_dir;
  /*!
   * 
   * - Name:  log_enable
   * - DefaultValue: log_enable
   */
  std::string m_log_enable;
  /*!
   * 
   * - Name:  odometryTimeOut
   * - DefaultValue: 3.0
   */
  float m_odometryTimeOut;
  /*!
   * 
   * - Name:  rangeTimeOut
   * - DefaultValue: 3.0
   */
  float m_rangeTimeOut;

  // </rtc-template>

  // DataInPort declaration
  // <rtc-template block="inport_declare">
  RTC::RangeData m_range;
  /*!
   */
  InPort<RTC::RangeData> m_rangeIn;
  RTC::TimedPose2D m_odometry;
  /*!
   */
  InPort<RTC::TimedPose2D> m_odometryIn;
  
  // </rtc-template>


  // DataOutPort declaration
  // <rtc-template block="outport_declare">
  RTC::TimedPose2D m_estimatedPose;
  /*!
   */
  OutPort<RTC::TimedPose2D> m_estimatedPoseOut;
  
  // </rtc-template>

  // CORBA Port declaration
  // <rtc-template block="corbaport_declare">
  /*!
   */
  RTC::CorbaPort m_gridMapperPort;
  
  // </rtc-template>

  // Service declaration
  // <rtc-template block="service_declare">
  /*!
   */
  OGMapperSVC_impl m_mapper;
  
  // </rtc-template>

  // Consumer declaration
  // <rtc-template block="consumer_declare">
  
  // </rtc-template>

 private:
  // <rtc-template block="private_attribute">
  
  // </rtc-template>

  // <rtc-template block="private_operation">
  
  // </rtc-template>


  ssr::MapBuilder* m_pMapBuilder;
  bool m_FirstExecution;
  ssr::Pose2D m_OldPose;
  ssr::Map m_Map;

  bool OdometryIsOutOfRange(TimedPose2D odometry);

  public:

	void getCurrentMap(RTC::OGMap_out map);
	int32_t startMapping();
	int32_t stopMapping();

  RTC::MAPPER_STATE getState();
  coil::Mutex m_mapperMutex;

  coil::TimeValue m_lastOdometryReceivedTime;
  coil::TimeValue m_lastRangeReceivedTime;

  MAPPER_MRPT_MODE m_Mode;

public:
  MAPPER_MRPT_MODE getMode(){return m_Mode;}

};


extern "C"
{
  DLL_EXPORT void Mapper_MRPTInit(RTC::Manager* manager);
};

#endif // MAPPER_MRPT_H
