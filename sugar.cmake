sugar_include(lib)
sugar_include(app)

# Folder 'test' have no sources. All sources for GTest located in 'lib' folder.
# Sugar will collect only data files for testing.
sugar_include(test)

# Do not dive into 'example' folder. Projects can be used stand-alone
# hence should collect sources themself.
