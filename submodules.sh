#!/usr/bin/env bash

git submodule update --init --single-branch --depth 1 # paper submodule

# see https://github.blog/open-source/git/get-up-to-speed-with-partial-clone-and-shallow-clone/
git submodule update --init --filter=blob:none --recursive --single-branch --depth 1 --jobs $(nproc)

# setup branch tracking, for submodules that specify a branch
git submodule foreach --recursive 'branch="$(git config -f "${toplevel}/.gitmodules" "submodule.${name}.branch" || true)"; [ -n "${branch}" ] || exit 0; git config remote.origin.fetch "+refs/heads/${branch}:refs/remotes/origin/${branch}"; git checkout -b "${branch}"; git fetch origin "${branch}" --filter=blob:none; git branch -u "origin/${branch}"; git config "branch.${branch}.remote" origin'
