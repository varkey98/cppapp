load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "new_git_repository")

new_git_repository(
  name = "drogon",
  remote = "https://github.com/drogonframework/drogon.git",
  recursive_init_submodules = True,
  tag = "v1.9.3",
  build_file_content = """
load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "drogon-hdrs",
    hdrs = glob([
      "lib/inc/**/*.h",
    ]),
    strip_include_prefix = "lib/inc",
    visibility = [
        "//visibility:public",
    ],
)
        """,
    )

http_archive(
    name = "spdlog-1.12.0",
    sha256 = "6174bf8885287422a6c6a0312eb8a30e8d22bcfcee7c48a6d02d1835d7769232",
    strip_prefix = "spdlog-1.12.0",
    url = "https://github.com/gabime/spdlog/archive/refs/tags/v1.12.0.zip",
    build_file_content = """
load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "spdlog",
    hdrs = glob(["include/**/*.h"]),
    strip_include_prefix = "include",
    visibility = [
        "//visibility:public",
    ],
)
        """,
    )

