#!/bin/bash

# Check if the alias already exists in the bash configuration file
if ! grep -q "alias dqb='./Daily_Quote_Bash/Daily_Quote_Bash'" ~/.bashrc; then
    # Add the alias to the bash configuration file
    echo "alias dqb='./Daily_Quote_Bash/Daily_Quote_Bash'" >> ~/.bashrc
    echo "Alias 'dqb' added to ~/.bashrc"
else
    echo "Alias 'dqb' already exists in ~/.bashrc"
fi

# Activate the alias for the current shell session
alias dqb='./Daily_Quote_Bash/Daily_Quote_Bash'

