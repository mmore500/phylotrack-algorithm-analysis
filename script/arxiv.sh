#!/bin/bash

set -e
shopt -s globstar

# replace symlinks (e.g., bibl.bib -> tex/bibl.bib) with their targets
find . -maxdepth 1 -type l -exec sh -c 'cp --remove-destination "$(readlink -f "$1")" "$1"' _ {} \;

find hereditary-stratigraph-concept -type f ! \( -name "*.pdf" -o -name "*.tex" -o -name "*.bib" \) -exec rm -f {} +


find . -type d -name dishtiny -exec rm -rf {} +
find . -type d -name hstrat -exec rm -rf {} +
find . -type d -name conduit -exec rm -rf {} +
find . -type d -name docs -exec rm -rf {} +
find . -type d -empty -delete
find . -type l -delete

find . -type f | grep -P '[^a-zA-Z0-9_+.,=/-]+' | xargs rm -rf
find . -name '.*' -not -name '.' -not -name '..' -exec rm {} \;

rm -f arxiv.tar.gz
make cleaner
make
make clean
mv bibl.bib main.bib
cp bu1.bbl main.bbl
cp bu1.blg main.blg
tar -czvf arxiv.tar.gz *
