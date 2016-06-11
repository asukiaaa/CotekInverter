//
// A Program to scan command of cotek-inverter
// Written by Asuki Kono 2016.05
// License: MIT
//
// Useage:
// #include "CotekInverter.h"
// #include "CotekInverterCommandChecker.h"
// CotekInverter inverter(8, 9); // RX, TX
// CotekInverterCommandChecker command_checker(&inverter);
// String command_to_start_from = "'sRJ";
//
// void setup() {
//   command_checker.set_command(command_to_start_from);
// }
// void loop() {
//   command_checker.check_command();
//   command_checker.update_to_next_command();
//    delay(10);
// }
//
//
// Found the following commands for SK-1500
// *RST // reset
// *RST
// *RSt
// *RsT
// *Rst
// Power 0 // power OFF
// Power 1 // power ON
// Power 2 // unknown
// Power 3 // returned values
//         // 0: off
//         // 2: on
// Power 4 // unknown
// Power 5 // unknown
// Power 6 // unknown
// Power 7 // unknown
// Power 8 // unknown
// Power 9 // unknown
//

#include "CotekInverterCommandChecker.h"

CotekInverterCommandChecker::CotekInverterCommandChecker( CotekInverter* inverter_to_check ) {
  inverter         = inverter_to_check;
  start_of_char    = char(32);  // space
  end_of_char      = char(127); // ~
  checking_command = start_of_char;
  found_commands   = "";
}

void CotekInverterCommandChecker::push_to_found_commands( String found_command ) {
  if ( found_commands.length() > 0 ) {
    found_commands += "\n";
  }
  found_commands += found_command;
}

void CotekInverterCommandChecker::set_command( String command_to_start_from ) {
  checking_command = command_to_start_from;
}

String CotekInverterCommandChecker::get_current_command() {
  return checking_command;
}

String CotekInverterCommandChecker::get_found_commands() {
  return found_commands;
}

void CotekInverterCommandChecker::update_to_next_command() {
  int command_length = checking_command.length();
  for ( int i = command_length - 1; i >= 0; i-- ) {

    // if a target char is end_of_char
    if ( checking_command[i] == end_of_char ) {
      checking_command[i] = start_of_char;

      // if the target end_of_char is a first char of command,
      // add new start_of_char to last of command
      if ( i == 0 ) {
        checking_command += start_of_char;
      } else {
        continue;
      }

    } else {
      checking_command[i] = int(checking_command[i]) + 1;
      return;
    }
  }
}

boolean CotekInverterCommandChecker::check_command() {
  inverter->send_signal(checking_command);

  //int info_len = inverter->send_signal(checking_command);
  //Serial.println(inverter.buff[0]);

  //for ( int len = 0; len < info_len; len ++ ) {
  //  Serial.println(inverter.buff[len]);
  //}

  if ( inverter->buff[0] != 63 ) {
    // founda a command!!
    push_to_found_commands(checking_command);
  }
}
