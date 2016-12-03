#ifndef CotekInverterCommandChecker_h
#define CotekInverterCommandChecker_h

#include <Arduino.h>
#include <SoftwareSerial.h>
#include "CotekInverter.h"

class CotekInverterCommandChecker {
  private:
  CotekInverter* inverter;
  String checking_command;
  String found_commands;
  char start_of_char;
  char end_of_char;
  void push_to_found_commands( String found_fommand );

  public:
  CotekInverterCommandChecker(CotekInverter* inverter_to_check);

  void set_command( String command_to_start_from );
  String get_current_command();
  String get_found_commands();
  void update_to_next_command();
  boolean check_command();
};

#endif
