 
// ArduPilotMega v2.2 config file (JLN development version tested in flight on MAJA UAV) 
// SETUP FOR THE Rembizi GPS EMULATOR v1.1.45
//
// Updated on 05-10-11: JLN added GPS emulator protocol for nav simulation with the Rembizi GPSemulator v1.1.45
// Updated on 05-06-11: JLN added full autonomous navigation in closed loop under flight plan for long tests runs
// Updated on 05-02-11: JLN added embedded Ardustation Protocol for the Ardustation v1.2

// -*- tab-width: 4; Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil -*-
 
//////////////////////////////////////////////////////////////////////////////
// GCS_PROTOCOL                             OPTIONAL
// GCS_PORT                                 OPTIONAL
// MAV_SYSTEM_ID							OPTIONAL
//
// The GCS_PROTOCOL option determines which (if any) ground control station
// protocol will be used.  Must be one of:
//
// GCS_PROTOCOL_NONE        No GCS output
// GCS_PROTOCOL_MAVLINK     QGroundControl protocol
//
// The GCS_PORT option determines which serial port will be used by the
// GCS protocol.   The usual values are 0 for the console/USB port,
// or 3 for the telemetry port on the oilpan.  Note that some protocols
// will ignore this value and always use the console port.
//
// The MAV_SYSTEM_ID is a unique identifier for this UAV.  The default value is 1. 
// If you will be flying multiple UAV's each should be assigned a different ID so 
// that ground stations can tell them apart.
//
#define GCS_PORT	    3
//#define GCS_PROTOCOL	    GCS_PROTOCOL_MAVLINK   // QGroundControl protocol
#define GCS_PROTOCOL	    GCS_PROTOCOL_NONE   // QGroundControl protocol
#define MAV_SYSTEM_ID	    1

// Add a ground start delay in seconds
#define GROUND_START_DELAY  0

#define INERTIAL_NAVIGATION     DISABLED    // enable/disable autonomous navigation with flight plan (JLN version)
#define CLOSED_LOOP_NAV         ENABLED     // set to ENABLED if closed loop navigation else set to DISABLED (Return To Lauch)

//////////////////////////////////////////////////////////////////////////////
// Ardustation embedded protocols added by JLN
//
// ADS_PROTOCOL_NONE        No ADS output
// ADS_PROTOCOL_JLN         Basic groundstation protocol for JLN Ardustation
// ADS_PROTOCOL_EMU         Rembizi gps simulator protocol
//
//#define ADS_PROTOCOL        ADS_PROTOCOL_JLN   // embedded Ardustation basic protocol (Added by JLN)
#define ADS_PROTOCOL        ADS_PROTOCOL_EMU     // Rembizi emulator protocol
//////////////////////////////////////////////////////////////////////////////
// Serial port speeds.
//
#define SERIAL0_BAUD        9600
#define SERIAL3_BAUD        115200

//////////////////////////////////////////////////////////////////////////////
// GPS_PROTOCOL 
//#define GPS_PROTOCOL        GPS_PROTOCOL_MTK16
#define GPS_PROTOCOL        GPS_PROTOCOL_EMU

#define MAGNETOMETER	    DISABLED
#define MAG_ORIENTATION	    AP_COMPASS_COMPONENTS_DOWN_PINS_FORWARD
//#define MAGCALIBRATION      25.217  // Paris Corrected   
#define MAGCALIBRATION       -0.217  // Paris    

#define AIRSPEED_SENSOR     DISABLED
#define AIRSPEED_RATIO      1.9936

//////////////////////////////////////////////////////////////////////////////
// THROTTLE_FAILSAFE                        OPTIONAL
// THROTTLE_FS_VALUE                        OPTIONAL
// THROTTLE_FAILSAFE_ACTION                 OPTIONAL
//
// The throttle failsafe allows you to configure a software failsafe activated
// by a setting on the throttle input channel (channel 3).
//
// This can be used to achieve a failsafe override on loss of radio control
// without having to sacrifice one of your FLIGHT_MODE settings, as the
// throttle failsafe overrides the switch-selected mode.
//
// Throttle failsafe is enabled by setting THROTTLE_FAILSAFE to 1.  The default
// is for it to be disabled.
//
// If the throttle failsafe is enabled, THROTTLE_FS_VALUE sets the channel value
// below which the failsafe engages.  The default is 975ms, which is a very low
// throttle setting.  Most transmitters will let you trim the manual throttle
// position up so that you cannot engage the failsafe with a regular stick movement.
//
// Configure your receiver's failsafe setting for the throttle channel to the
// absolute minimum, and use the ArduPilotMega_demo program to check that
// you cannot reach that value with the throttle control.  Leave a margin of
// at least 50 microseconds between the lowest throttle setting and
// THROTTLE_FS_VALUE.
//
// The FAILSAFE_ACTION setting determines what APM will do when throttle failsafe
// mode is entered while flying in AUTO mode.  This is important in order to avoid
// accidental failsafe behaviour when flying waypoints that take the aircraft
// temporarily out of radio range.
//
// If FAILSAFE_ACTION is 1, when failsafe is entered in AUTO or LOITER modes,
// the aircraft will head for home in RTL mode.  If the throttle channel moves
// back up, it will return to AUTO or LOITER mode.
//
// The default behaviour is to ignore throttle failsafe in AUTO and LOITER modes.
//
//#define THROTTLE_FAILSAFE   DISABLED
//#define THROTTLE_FS_VALUE   975
//#define THROTTLE_FAILSAFE_ACTION 2
#define THROTTLE_FAILSAFE   DISABLED

//////////////////////////////////////////////////////////////////////////////
// THROTTLE_OUT                             DEBUG
//
// When debugging, it can be useful to disable the throttle output.  Set
// this option to DISABLED to disable throttle output signals.
//
// The default is to not disable throttle output.
//
#define THROTTLE_OUT        ENABLED

#define HIL_MODE            HIL_MODE_DISABLED    //  Configure for standard flight.
#define HIL_PORT	    3
#define HIL_PROTOCOL	    HIL_PROTOCOL_MAVLINK 

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
// RADIO CONFIGURATION
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
// FLIGHT_MODE								OPTIONAL
// FLIGHT_MODE_CHANNEL			    		OPTIONAL
//
// Flight modes assigned to the control channel, and the input channel that
// is read for the control mode.
//
// Use a servo tester, or the ArduPilotMega_demo test program to check your
// switch settings.
//
// ATTENTION: Some ArduPilot Mega boards have radio channels marked 0-7, and
// others have them marked the standard 1-8.  The FLIGHT_MODE_CHANNEL option
// uses channel numbers 1-8 (and defaults to 8).
//
// If you only have a three-position switch or just want three modes, set your
// switch to produce 1165, 1425, and 1815 microseconds and configure
// FLIGHT_MODE 1 & 2, 3 & 4 and 5 & 6 to be the same.  This is the default.
//
// If you have FLIGHT_MODE_CHANNEL set to 8 (the default) and your control
// channel connected to input channel 8, the hardware failsafe mode will
// activate for any control input over 1750ms.
//
// For more modes (up to six), set your switch(es) to produce any of 1165,
// 1295, 1425, 1555, 1685, and 1815 microseconds.
//
// Flight mode |  Switch Setting (ms)
// ------------+---------------------
//      1      |     1165
//      2      |     1295
//      3      |     1425
//      4      |     1555
//      5      |     1685
//      6      |     1815	(FAILSAFE if using channel 8)
//
// The following standard flight modes are available:
//
//  Name            | Description
// -----------------+--------------------------------------------
//                  |
//  MANUAL          | Full manual control via the hardware multiplexer.
//                  |
//  STABILIZE       | Tries to maintain level flight, but can be overridden with radio control inputs.
//                  |
//  FLY_BY_WIRE_A   | Autopilot style control via user input, with manual throttle.
//                  |
//  FLY_BY_WIRE_B   | Autopilot style control via user input, aispeed controlled with throttle.
//                  |
//  RTL             | Returns to the Home location and then LOITERs at a safe altitude.
//                  |
//  AUTO            | Autonomous flight based on programmed waypoints.  Use the WaypointWriter
//                  | application or your Ground Control System to edit and upload
//                  | waypoints and other commands.
//                  |
//air
//
// The following non-standard modes are EXPERIMENTAL:
//
//  Name            | Description
// -----------------+--------------------------------------------
//                  |
//  LOITER          | Flies in a circle around the current location.
//                  |
//  CIRCLE          | Flies in a stabilized 'dumb' circle.
//                  |
//
//
// If you are using channel 8 for mode switching then FLIGHT_MODE_5 and
// FLIGHT_MODE_6 should be MANUAL.
//
//
#define FLIGHT_MODE_CHANNEL	8

#define FLIGHT_MODE_1         RTL          // pos 0
#define FLIGHT_MODE_2         RTL          // pos 1
#define FLIGHT_MODE_3         AUTO         // pos 2
#define FLIGHT_MODE_4         STABILIZE    // pos 3
#define FLIGHT_MODE_5         MANUAL       // pos 4
#define FLIGHT_MODE_6         MANUAL       // pos 5

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
// FLIGHT AND NAVIGATION CONTROL
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
// Altitude measurement and control.
//
// AOA                                      OPTIONAL
//
// The angle in 100ths of a degree that the nose of the aircraft should be
// raised from horizontal in level flight.  The default is 0 degree.
//
#define AOA                 0 // note, 100ths of a degree
//
// ALT_EST_GAIN                             OPTIONAL
//
// The gain of the altitude estimation function; a lower number results
// in slower error correction and smoother output.  The default is a
// reasonable starting point.
//
#define ALT_EST_GAIN        0.01

//
// ALTITUDE_MIX                             OPTIONAL
//
// Configures the blend between GPS and pressure altitude.
// 0 = GPS altitude, 1 = Press alt, 0.5 = half and half, etc.
//
// The default is to use only pressure altitude.
//
#define ALTITUDE_MIX        1
//

//////////////////////////////////////////////////////////////////////////////
// AIRSPEED_CRUISE                          OPTIONAL
//
// The speed in metres per second to maintain during cruise.  The default
// is 10m/s, which is a conservative value suitable for relatively small,
// light aircraft.
//
#define AIRSPEED_CRUISE     16  //12
//

//////////////////////////////////////////////////////////////////////////////
// FLY_BY_WIRE_B airspeed control (also used for throttle "nudging" in AUTO)
//
// AIRSPEED_FBW_MIN                         OPTIONAL
// AIRSPEED_FBW_MAX                         OPTIONAL
//
// Airspeed corresponding to minimum and maximum throttle in Fly By Wire B mode.
// The defaults are 6 and 30 metres per second.
//
// AIRSPEED_FBW_MAX also sets the maximum airspeed that the cruise airspeed can be "nudged" to in AUTO mode when ENABLE_STICK_MIXING is set.
// In AUTO the cruise airspeed can be increased between AIRSPEED_CRUISE and AIRSPEED_FBW_MAX by positioning the throttle
// stick in the top 1/2 of its range.  Throttle stick in the bottom 1/2 provide regular AUTO control.
//
#define AIRSPEED_FBW_MIN    6
#define AIRSPEED_FBW_MAX    22
//

//////////////////////////////////////////////////////////////////////////////
// Servo mapping
//
// THROTTLE_MIN                             OPTIONAL
//
// The minimum throttle setting to which the autopilot will reduce the
// throttle while descending.  The default is zero, which is
// suitable for aircraft with a steady power-off glide.  Increase this
// value if your aircraft needs throttle to maintain a stable descent in
// level flight.
//
// THROTTLE_CRUISE                          OPTIONAL
//
// The approximate throttle setting to achieve AIRSPEED_CRUISE in level flight.
// The default is 45%, which is reasonable for a modestly powered aircraft.
//
// THROTTLE_MAX                             OPTIONAL
//
// The maximum throttle setting the autopilot will apply.  The default is 75%.
// Reduce this value if your aicraft is overpowered, or has complex flight
// characteristics at high throttle settings.
//
#define THROTTLE_MIN		20  // percent
#define THROTTLE_CRUISE		35  // 45
#define THROTTLE_MAX		75  // 75

//////////////////////////////////////////////////////////////////////////////
// AUTO_TRIM                                OPTIONAL
//
// ArduPilot Mega can update its trim settings by looking at the
// radio inputs when switching out of MANUAL mode.  This allows you to
// manually trim your aircraft before switching to an assisted mode, but it
// also means that you should avoid switching out of MANUAL while you have
// any control stick deflection.
//
// The default is to enable AUTO_TRIM.
//
#define AUTO_TRIM           DISABLED

//////////////////////////////////////////////////////////////////////////////
// Autopilot control limits
//
// HEAD_MAX                                 OPTIONAL
//
// The maximum commanded bank angle in either direction.
// The default is 45 degrees.  Decrease this value if your aircraft is not
// stable or has difficulty maintaining altitude in a steep bank.
//
// PITCH_MAX                                OPTIONAL
//
// The maximum commanded pitch up angle.
// The default is 15 degrees.  Care should be taken not to set this value too
// large, as the aircraft may stall.
//
// PITCH_MIN
//
// The maximum commanded pitch down angle.  Note that this value must be
// negative.  The default is -25 degrees.  Care should be taken not to set
// this value too large as it may result in overspeeding the aircraft.
//
// PITCH_TARGET
//
// The target pitch for cruise flight.  When the APM measures this pitch
// value, the pitch error will be calculated to be 0 for the pitch PID
// control loop.
//
#define HEAD_MAX            40  // 45
#define PITCH_MAX           15
#define PITCH_MIN           -25
#define PITCH_TARGET        0

//////////////////////////////////////////////////////////////////////////////
// Attitude control gains
//
// Tuning values for the attitude control PID loops.
//
// The P term is the primary tuning value.  This determines how the control
// deflection varies in proportion to the required correction.
//
// The I term is used to help control surfaces settle.  This value should
// normally be kept low.
//
// The D term is used to control overshoot.  Avoid using or adjusting this
// term if you are not familiar with tuning PID loops.  It should normally
// be zero for most aircraft.
//
// Note: When tuning these values, start with changes of no more than 25% at
// a time.
//
// SERVO_ROLL_P                             OPTIONAL
// SERVO_ROLL_I                             OPTIONAL
// SERVO_ROLL_D                             OPTIONAL
//
// P, I and D terms for roll control.  Defaults are 0.4, 0, 0.
//
// SERVO_ROLL_INT_MAX                       OPTIONAL
//
// Maximum control offset due to the integral.  This prevents the control
// output from being overdriven due to a persistent offset (e.g. crosstracking).
// Default is 5 degrees.
//
// ROLL_SLEW_LIMIT                          EXPERIMENTAL
//
// Limits the slew rate of the roll control in degrees per second.  If zero,
// slew rate is not limited.  Default is to not limit the roll control slew rate.
// (This feature is currently not implemented.)
//
// SERVO_PITCH_P                            OPTIONAL
// SERVO_PITCH_I                            OPTIONAL
// SERVO_PITCH_D                            OPTIONAL
//
// P, I and D terms for the pitch control.  Defaults are 0.6, 0, 0.
//
// SERVO_PITCH_INT_MAX                      OPTIONAL
//
// Maximum control offset due to the integral.  This prevents the control
// output from being overdriven due to a persistent offset (e.g. native flight
// AoA).  If you find this value is insufficient, consider adjusting the AOA
// parameter.
// Default is 5 degrees.
//
// PITCH_COMP                               OPTIONAL
//
// Adds pitch input to compensate for the loss of lift due to roll control.
// Default is 0.20 (20% of roll control also applied to pitch control).
//
// SERVO_YAW_P                              OPTIONAL
// SERVO_YAW_I                              OPTIONAL
// SERVO_YAW_D                              OPTIONAL
//
// P, I and D terms for the YAW control.  Defaults are 0., 0., 0.
// Note units of this control loop are unusual.  PID input is in m/s**2.
//
// SERVO_YAW_INT_MAX                        OPTIONAL
//
// Maximum control offset due to the integral.  This prevents the control
// output from being overdriven due to a persistent offset (e.g. crosstracking).
// Default is 0.
//
// RUDDER_MIX                               OPTIONAL
//
// Roll to yaw mixing.  This allows for co-ordinated turns.
// Default is 0.50 (50% of roll control also applied to yaw control.)
//
#define SERVO_ROLL_P        0.8
#define SERVO_ROLL_I        0.0
#define SERVO_ROLL_D        0.0
#define SERVO_ROLL_INT_MAX  5
#define ROLL_SLEW_LIMIT     0
#define SERVO_PITCH_P       0.8
#define SERVO_PITCH_I       0.0
#define SERVO_PITCH_D       0.0
#define SERVO_PITCH_INT_MAX 5
#define PITCH_COMP          0.2
#define SERVO_YAW_P         0.5		// Default is zero.  A suggested value if you want to use this parameter is 0.5
#define SERVO_YAW_I         0.0
#define SERVO_YAW_D         0.0
#define SERVO_YAW_INT_MAX   5
#define RUDDER_MIX          0.5
//
//////////////////////////////////////////////////////////////////////////////
// Navigation control gains
//
// Tuning values for the navigation control PID loops.
//
// The P term is the primary tuning value.  This determines how the control
// deflection varies in proportion to the required correction.
//
// The I term is used to control drift.
//
// The D term is used to control overshoot.  Avoid adjusting this term if
// you are not familiar with tuning PID loops.
//
// Note: When tuning these values, start with changes of no more than 25% at
// a time.
//
// NAV_ROLL_P                               OPTIONAL
// NAV_ROLL_I                               OPTIONAL
// NAV_ROLL_D                               OPTIONAL
//
// P, I and D terms for navigation control over roll, normally used for
// controlling the aircraft's course.  The P term controls how aggressively
// the aircraft will bank to change or hold course.
// Defaults are 0.7, 0.0, 0.02.
//
// NAV_ROLL_INT_MAX                         OPTIONAL
//
// Maximum control offset due to the integral.  This prevents the control
// output from being overdriven due to a persistent offset (e.g. crosstracking).
// Default is 5 degrees.
//
// NAV_PITCH_ASP_P                          OPTIONAL
// NAV_PITCH_ASP_I                          OPTIONAL
// NAV_PITCH_ASP_D                          OPTIONAL
//
// P, I and D terms for pitch adjustments made to maintain airspeed.
// Defaults are 0.65, 0, 0.
//
// NAV_PITCH_ASP_INT_MAX                    OPTIONAL
//
// Maximum pitch offset due to the integral.  This limits the control
// output from being overdriven due to a persistent offset (eg. inability
// to maintain the programmed airspeed).
// Default is 5 degrees.
//
// NAV_PITCH_ALT_P                          OPTIONAL
// NAV_PITCH_ALT_I                          OPTIONAL
// NAV_PITCH_ALT_D                          OPTIONAL
//
// P, I and D terms for pitch adjustments made to maintain altitude.
// Defaults are 0.65, 0, 0.
//
// NAV_PITCH_ALT_INT_MAX                    OPTIONAL
//
// Maximum pitch offset due to the integral.  This limits the control
// output from being overdriven due to a persistent offset (eg. inability
// to maintain the programmed altitude).
// Default is 5 meters.
//
#define NAV_ROLL_P          0.4 //0.7
#define NAV_ROLL_I          0.0 //0.01
#define NAV_ROLL_D          0.0 //0.02
#define NAV_ROLL_INT_MAX    5

#define NAV_PITCH_ASP_P     0.65
#define NAV_PITCH_ASP_I     0.0
#define NAV_PITCH_ASP_D     0.0
#define NAV_PITCH_ASP_INT_MAX 5

#define NAV_PITCH_ALT_P     0.65
#define NAV_PITCH_ALT_I     0.0
#define NAV_PITCH_ALT_D     0.0
#define NAV_PITCH_ALT_INT_MAX 5

//////////////////////////////////////////////////////////////////////////////
// Energy/Altitude control gains
//
// The Energy/altitude control system uses throttle input to control aircraft
// altitude.
//
// The P term is the primary tuning value.  This determines how the throttle
// setting varies in proportion to the required correction.
//
// The I term is used to compensate for small offsets.
//
// The D term is used to control overshoot.  Avoid adjusting this term if
// you are not familiar with tuning PID loops.
//
// Note units of this control loop are unusual.  PID input is in m**2/s**2.
//
// THROTTLE_TE_P                            OPTIONAL
// THROTTLE_TE_I                            OPTIONAL
// THROTTLE_TE_D                            OPTIONAL
//
// P, I and D terms for throttle adjustments made to control altitude.
// Defaults are 0.5, 0, 0.
//
// THROTTLE_TE_INT_MAX                      OPTIONAL
//
// Maximum throttle input due to the integral term.  This limits the
// throttle from being overdriven due to a persistent offset (e.g.
// inability to maintain the programmed altitude).
// Default is 20%.
//
// THROTTLE_SLEW_LIMIT                      OPTIONAL
//
// Limits the slew rate of the throttle, in percent per second.  Helps
// avoid sudden throttle changes, which can destabilise the aircraft.
// A setting of zero disables the feature.
// Default is zero (disabled).
//
// P_TO_T                                   OPTIONAL
//
// Pitch to throttle feed-forward gain.  Default is 0.
//
// T_TO_P                                   OPTIONAL
//
// Throttle to pitch feed-forward gain.  Default is 0.
//
#define THROTTLE_TE_P       0.50
#define THROTTLE_TE_I       0.0
#define THROTTLE_TE_D       0.0
#define THROTTLE_TE_INT_MAX 20
#define THROTTLE_SLEW_LIMIT 0
#define P_TO_T              0
#define T_TO_P              0

//////////////////////////////////////////////////////////////////////////////
// Crosstrack compensation
//
// XTRACK_GAIN                              OPTIONAL
//
// Crosstrack compensation in degrees per metre off track.
// Default value is 1.0 degrees per metre.  Values lower than 0.001 will
// disable crosstrack compensation.
//
// XTRACK_ENTRY_ANGLE                       OPTIONAL
//
// Maximum angle used to correct for track following.
// Default value is 30 degrees.
//
#define XTRACK_GAIN         1  // deg/m
#define XTRACK_ENTRY_ANGLE  10  // 30 // deg

/////////////////////////////////////////////////////////////////////////////
// Navigation defaults
//
// WP_RADIUS_DEFAULT                        OPTIONAL
//
// When the user performs a factory reset on the APM, set the waypoint radius
// (the radius from a target waypoint within which the APM will consider
// itself to have arrived at the waypoint) to this value in meters.  This is
// mainly intended to allow users to start using the APM without running the
// WaypointWriter first.
//
// LOITER_RADIUS_DEFAULT                    OPTIONAL
//
// When the user performs a factory reset on the APM, set the loiter radius
// (the distance the APM will attempt to maintain from a waypoint while
// loitering) to this value in meters.  This is mainly intended to allow
// users to start using the APM without running the WaypointWriter first.
//
// USE_CURRENT_ALT							OPTIONAL
// ALT_HOLD_HOME							OPTIONAL
//
// When the user performs a factory reset on the APM, set the flag for weather
// the current altitude or ALT_HOLD_HOME altitude should be used for Return To Launch.
// Also, set the value of USE_CURRENT_ALT in meters.  This is mainly intended to allow
// users to start using the APM without running the WaypointWriter first.
//
#define WP_RADIUS_DEFAULT	30
#define LOITER_RADIUS_DEFAULT	60
#define USE_CURRENT_ALT		TRUE
#define ALT_HOLD_HOME		100

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
// DEBUGGING
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
// Dataflash logging control
//
// Each of these logging options may be set to ENABLED to enable, or DISABLED
// to disable the logging of the respective data.
//
// LOG_ATTITUDE_FAST                        DEBUG
//
// Logs basic attitude info to the dataflash at 50Hz (uses more space).
// Defaults to DISABLED.
//
// LOG_ATTITUDE_MED                         OPTIONAL
//
// Logs basic attitude info to the dataflash at 10Hz (uses less space than
// LOG_ATTITUDE_FAST).  Defaults to ENABLED.
//
// LOG_GPS                                  OPTIONAL
//
// Logs GPS info to the dataflash at 10Hz.  Defaults to ENABLED.
//
// LOG_PM                                   OPTIONAL
//
// Logs IMU performance monitoring info every 20 seconds.
// Defaults to DISABLED.
//
// LOG_CTUN                                 OPTIONAL
//
// Logs control loop tuning info at 10 Hz.  This information is useful for tuning
// servo control loop gain values.  Defaults to DISABLED.
//
// LOG_NTUN                                 OPTIONAL
//
// Logs navigation tuning info at 10 Hz.  This information is useful for tuning
// navigation control loop gain values.  Defaults to DISABLED.
//
// LOG_ MODE                                OPTIONAL
//
// Logs changes to the flight mode upon occurrence.  Defaults to ENABLED.
//
// LOG_RAW                                  DEBUG
//
// Logs raw accelerometer and gyro data at 50 Hz (uses more space).
// Defaults to DISABLED.
//
// LOG_CMD                                  OPTIONAL
//
// Logs new commands when they process.
// Defaults to ENABLED.
//
#define LOG_ATTITUDE_FAST   DISABLED
#define LOG_ATTITUDE_MED    DISABLED
#define LOG_GPS             DISABLED
#define LOG_PM              DISABLED
#define LOG_CTUN            DISABLED
#define LOG_NTUN            DISABLED
#define LOG_MODE            DISABLED
#define LOG_RAW             DISABLED
#define LOG_CMD             DISABLED
#define LOG_CUR	            DISABLED

//////////////////////////////////////////////////////////////////////////////
// Battery monitoring                       OPTIONAL
//
// See the manual for details on selecting divider resistors for battery
// monitoring via the oilpan.
//
// BATTERY_EVENT                            OPTIONAL
//
// Set BATTERY_EVENT to ENABLED to enable low voltage or high discharge warnings.  
// The default is DISABLED.
//
// LOW_VOLTAGE                              OPTIONAL if BATTERY_EVENT is set.
//
// Value in volts at which ArduPilot Mega should consider the
// battery to be "low".
//
// VOLT_DIV_RATIO                           OPTIONAL
//
// See the manual for details.  The default value corresponds to the resistors
// recommended by the manual.
//
// CURR_AMPS_PER_VOLT						OPTIONAL
// CURR_AMPS_OFFSET						OPTIONAL
//
// The sensitivity of the current sensor.  This must be scaled if a resistor is installed on APM
// for a voltage divider on input 2 (not recommended).  The offset is used for current sensors with an offset
//
//
// HIGH_DISCHARGE							OPTIONAL if BATTERY_EVENT is set.
//
// Value in milliamp-hours at which a warning should be triggered.  Recommended value = 80% of 
// battery capacity.
//
#define BATTERY_EVENT			DISABLED
#define LOW_VOLTAGE			9.6
#define VOLT_DIV_RATIO		        3.56
//#define CURR_AMPS_PER_VOLT	        27.32	
//#define CURR_AMPS_OFFSET		0.0	
//#define HIGH_DISCHARGE		1760

//////////////////////////////////////////////////////////////////////////////
// INPUT_VOLTAGE                            OPTIONAL
//
// In order to have accurate pressure and battery voltage readings, this
// value should be set to the voltage measured on the 5V rail on the oilpan.
//
// See the manual for more details.  The default value should be close.
//
#define INPUT_VOLTAGE 4.8
//


