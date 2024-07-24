#!/bin/bash

base_dir="$(dirname "$(realpath "${BASH_SOURCE[0]}")")"
env_path="$HOME/env/zephyr"

source $env_path/bin/activate

if ! command -v west &> /dev/null; then
   echo "West is not available. Something is wrong !!"
else
   echo "West is available."
fi
