//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "indentationTestApp.h"
#include "indentationApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

template <>
InputParameters
validParams<indentationTestApp>()
{
  InputParameters params = validParams<indentationApp>();
  return params;
}

indentationTestApp::indentationTestApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  indentationApp::registerObjectDepends(_factory);
  indentationApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  indentationApp::associateSyntaxDepends(_syntax, _action_factory);
  indentationApp::associateSyntax(_syntax, _action_factory);

  Moose::registerExecFlags(_factory);
  ModulesApp::registerExecFlags(_factory);
  indentationApp::registerExecFlags(_factory);

  bool use_test_objs = getParam<bool>("allow_test_objects");
  if (use_test_objs)
  {
    indentationTestApp::registerObjects(_factory);
    indentationTestApp::associateSyntax(_syntax, _action_factory);
    indentationTestApp::registerExecFlags(_factory);
  }
}

indentationTestApp::~indentationTestApp() {}

void
indentationTestApp::registerApps()
{
  registerApp(indentationApp);
  registerApp(indentationTestApp);
}

void
indentationTestApp::registerObjects(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new test objects here! */
}

void
indentationTestApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
  /* Uncomment Syntax and ActionFactory parameters and register your new test objects here! */
}

void
indentationTestApp::registerExecFlags(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new execute flags here! */
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
indentationTestApp__registerApps()
{
  indentationTestApp::registerApps();
}

// External entry point for dynamic object registration
extern "C" void
indentationTestApp__registerObjects(Factory & factory)
{
  indentationTestApp::registerObjects(factory);
}

// External entry point for dynamic syntax association
extern "C" void
indentationTestApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  indentationTestApp::associateSyntax(syntax, action_factory);
}

// External entry point for dynamic execute flag loading
extern "C" void
indentationTestApp__registerExecFlags(Factory & factory)
{
  indentationTestApp::registerExecFlags(factory);
}
