add_executable(mediakit_contracts_test
    test_media_contracts.cpp
)

target_link_libraries(mediakit_contracts_test PRIVATE MediaKit::Core)
add_test(NAME mediakit_contracts_test COMMAND mediakit_contracts_test)
