#!/usr/bin/env bash

# this command cleans up the formatting of java code
# this helps to keep consisten formatting of the code in the repository

eclipse -application org.eclipse.jdt.core.JavaCodeFormatter -nosplash -verbose -config .settings/org.eclipse.jdt.core.prefs src/
