# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "")
  file(REMOVE_RECURSE
  "C:\\Users\\bb155134\\OneDrive - Renishaw plc\\Oscillator\\Software\\Oscillator\\out\\Oscillator\\Debug.eep"
  "C:\\Users\\bb155134\\OneDrive - Renishaw plc\\Oscillator\\Software\\Oscillator\\out\\Oscillator\\Debug.hex"
  "C:\\Users\\bb155134\\OneDrive - Renishaw plc\\Oscillator\\Software\\Oscillator\\out\\Oscillator\\Debug.lss"
  "C:\\Users\\bb155134\\OneDrive - Renishaw plc\\Oscillator\\Software\\Oscillator\\out\\Oscillator\\Debug.srec"
  "C:\\Users\\bb155134\\OneDrive - Renishaw plc\\Oscillator\\Software\\Oscillator\\out\\Oscillator\\Debug.usersignatures"
  )
endif()
