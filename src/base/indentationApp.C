#include "indentationApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<indentationApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

indentationApp::indentationApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  indentationApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  indentationApp::associateSyntax(_syntax, _action_factory);

  Moose::registerExecFlags(_factory);
  ModulesApp::registerExecFlags(_factory);
  indentationApp::registerExecFlags(_factory);
}

indentationApp::~indentationApp() {}

void
indentationApp::registerApps()
{
  registerApp(indentationApp);
}

void
indentationApp::registerObjects(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new production objects here! */
}

void
indentationApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
  /* Uncomment Syntax and ActionFactory parameters and register your new production objects here! */
}

void
indentationApp::registerObjectDepends(Factory & /*factory*/)
{
}

void
indentationApp::associateSyntaxDepends(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}

void
indentationApp::registerExecFlags(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new execution flags here! */
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
indentationApp__registerApps()
{
  indentationApp::registerApps();
}

extern "C" void
indentationApp__registerObjects(Factory & factory)
{
  indentationApp::registerObjects(factory);
}

extern "C" void
indentationApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  indentationApp::associateSyntax(syntax, action_factory);
}

extern "C" void
indentationApp__registerExecFlags(Factory & factory)
{
  indentationApp::registerExecFlags(factory);
}
