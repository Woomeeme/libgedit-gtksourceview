#!/bin/sh

lang_file="$1"

xmllint --relaxng 'default-language-specs/language2.rng' --noout "${lang_file}"
