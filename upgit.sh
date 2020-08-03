#!/bin/bash
echo "Enviando para o GIT"
git add .
git pull origin master
echo "digite o texto do commit"
read txtcmt
git commit -m "$txtcmt"
git push origin master

