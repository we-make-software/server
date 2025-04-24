#!/bin/bash
sudo cp WeMakeSoftware.service /etc/systemd/system/
sudo systemctl daemon-reexec
sudo systemctl enable WeMakeSoftware.service