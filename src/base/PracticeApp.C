#include "PracticeApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template<>
InputParameters validParams<PracticeApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

PracticeApp::PracticeApp(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  PracticeApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  PracticeApp::associateSyntax(_syntax, _action_factory);
}

PracticeApp::~PracticeApp()
{
}

// External entry point for dynamic application loading
extern "C" void PracticeApp__registerApps() { PracticeApp::registerApps(); }
void
PracticeApp::registerApps()
{
  registerApp(PracticeApp);
}

// External entry point for dynamic object registration
extern "C" void PracticeApp__registerObjects(Factory & factory) { PracticeApp::registerObjects(factory); }
void
PracticeApp::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void PracticeApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { PracticeApp::associateSyntax(syntax, action_factory); }
void
PracticeApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
