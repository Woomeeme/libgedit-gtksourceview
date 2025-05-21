#!/bin/sh

for lang_file in default-language-specs/*.lang
do
	./check-language.sh "${lang_file}" || exit 1
done
