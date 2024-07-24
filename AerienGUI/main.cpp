/**
 * @file main.cpp
 * @brief Main entry point to the Qt application for airport management.
 *
 * This file contains the application's main function, which initializes and executes the Qt application.
 * the Qt application, and creates and displays the application's main window.
 * * \author Chih Taki-eddine
 * * \date 07 Juillet 2024
 */
#include "Airport_Table.h"
#include <QApplication>
#include "Airport.h"

/**
 * @file main.cpp
 * @brief Main entry point for the Qt application managing airports.
 *
 * This file contains the main function of the application, which initializes and runs
 * the Qt application, creates and displays the main window of the application.
 * 
 * @author Chih Taki-eddine
 * @date 07 July 2024
 */

/**
 * @brief Main function of the Qt application.
 *
 * This function initializes the Qt application, creates and displays the main window
 * (Airport_Table), and starts the application's event loop.
 *
 * @param argc Number of command-line arguments.
 * @param argv Array of command-line arguments.
 * @return Application exit code.
 */
int main (int argc, char *argv[])
{
  // initialize resources, if needed
  // Q_INIT_RESOURCE(resfile);

  QApplication app (argc, argv);

  // create and show your widgets here
  Airport_Table table;
  table.show();

  return app.exec ();
}
