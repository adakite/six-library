#!/usr/bin/env python

#
# =========================================================================
# This file is part of six.sicd-python
# =========================================================================
#
# (C) Copyright 2004 - 2016, MDA Information Systems LLC
#
# six.sicd-python is free software; you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as published by
# the Free Software Foundation; either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public
# License along with this program; If not,
# see <http://www.gnu.org/licenses/>.
#

import os
from subprocess import call

import utils

def run():
    install = utils.installPath()
    unitTestDir = os.path.join(install, 'unittests')
    childDirs = os.listdir(unitTestDir)
    success = True
    for childDir in childDirs:
        for test in os.listdir(os.path.join(unitTestDir, childDir)):
            print(os.path.join(unitTestDir, childDir, test))
            if call([utils.executableName(os.path.join(unitTestDir, childDir, test))]) != 0:
                success = False

    return success

if __name__ == '__main__':
    run()
    
