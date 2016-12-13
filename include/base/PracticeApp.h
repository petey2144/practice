#ifndef PRACTICEAPP_H
#define PRACTICEAPP_H

#include "MooseApp.h"

class PracticeApp;

template<>
InputParameters validParams<PracticeApp>();

class PracticeApp : public MooseApp
{
public:
  PracticeApp(InputParameters parameters);
  virtual ~PracticeApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* PRACTICEAPP_H */
