#pragma once

#include "Commands/command.h"
#include <string>
#include <memory>
#include "ResourceManager.h"

class MusicCommand : public Command {
public:
    MusicCommand();
    virtual void execute()  override;
private:
  
};
