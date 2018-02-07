	cmake_minimum_required(VERSION 3.4)
	project(Biblioteka)

	#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

	set(SOURCE_FILES
	    src/funkcje.cpp
	    src/Student.cpp
	    src/model/Client.cpp
	    src/model/Address.cpp
	    src/model/Rent.cpp
	    src/model/Vehicle.cpp
	    src/model/Mope.cpp
	    src/model/MotorVehicle.cpp
	    src/model/Car.cpp
	    src/model/Bicycle.cpp
	    src/model/Segment.cpp
	    src/model/CurrentRentsRepository.cpp
	    src/model/VehicleRepository.cpp
	    src/model/ClientRepository.cpp
	    src/model/ClientType.cpp
	    src/model/RentsManager.cpp
	    src/model/ClientManager.cpp
	    src/model/VehicleManager.cpp
	    src/model/client_types/FrequentClient.cpp
	    src/model/client_types/NormalClient.cpp
	    src/model/RentsRepository.cpp

	    src/model/exceptions/ClientException.cpp
	    src/model/exceptions/RentException.cpp
	)

	add_library(Biblioteka ${SOURCE_FILES})

	#dolacz katalog z plikami naglowkowymi include z projektu biblioteka do sciezek
	target_include_directories(Biblioteka PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
	target_include_directories(Biblioteka PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/model)
	target_include_directories(Biblioteka PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/model/client_types)
	target_include_directories(Biblioteka PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/model/exceptions)
	target_include_directories(Biblioteka PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/model/templates)

	#Sekcja testów
	find_package (Boost 1.58.0 COMPONENTS "unit_test_framework" REQUIRED)

	set(SOURCE_TEST_FILES
		test/master.cpp
		test/StudentTest.cpp
		)


	include_directories(
		${CMAKE_CURRENT_SOURCE_DIR}/include
		${Boost_INCLUDE_DIRS}
	)

	# Konfiguracja QT
	find_package(Qt5Widgets)

	add_executable (Test ${SOURCE_TEST_FILES})

	set(SOURCE_RENT_FILES
		test/master.cpp
		test/RentTest.cpp
		)

	add_executable (RentTest ${SOURCE_RENT_FILES})

	target_link_libraries (Test
		Biblioteka
		${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
		Qt5::Widgets
        )
target_link_libraries (RentTest
        Biblioteka
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        -lboost_date_time
        )
#CarTest
set(SOURCE_CAR_FILES test/master.cpp test/CarTest.cpp)
add_executable (CarTest ${SOURCE_CAR_FILES})
target_link_libraries (CarTest Biblioteka ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

#MopeTest
set(SOURCE_MOPE_FILES test/master.cpp test/MopeTest.cpp)
add_executable (MopeTest ${SOURCE_MOPE_FILES})
target_link_libraries (MopeTest Biblioteka ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

#BicycleTest
set(SOURCE_BICYCLE_FILES test/master.cpp test/BicycleTest.cpp)
add_executable (BicycleTest ${SOURCE_BICYCLE_FILES})
target_link_libraries (BicycleTest Biblioteka ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

#ClientTest
set(SOURCE_CLIENT_FILES test/master.cpp test/ClientTest.cpp)
add_executable (ClientTest ${SOURCE_CLIENT_FILES})
target_link_libraries (ClientTest Biblioteka -g ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} -lboost_date_time)

#AddressTest
set(SOURCE_ADDRESS_FILES test/master.cpp test/AddressTest.cpp)
add_executable (AddressTest ${SOURCE_ADDRESS_FILES})
target_link_libraries (AddressTest Biblioteka ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

#VehicleRepositoryTest
set(SOURCE_VEHICLE_REPOSITORY_FILES test/master.cpp test/VehicleRepositoryTest.cpp)
add_executable (VehicleRepositoryTest ${SOURCE_VEHICLE_REPOSITORY_FILES})
target_link_libraries (VehicleRepositoryTest Biblioteka ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

#CurrentRentsRepositoryTest
set(SOURCE_CURRENT_RENTS_REPOSITORY_FILES test/master.cpp test/CurrentRentsRepositoryTest.cpp)
add_executable (CurrentRentsRepositoryTest ${SOURCE_CURRENT_RENTS_REPOSITORY_FILES})
target_link_libraries (CurrentRentsRepositoryTest Biblioteka ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} -lboost_date_time)

#ClientRepositoryTest
set(SOURCE_CLIENT_REPOSITORY_FILES test/master.cpp test/ClientRepositoryTest.cpp)
add_executable (ClientRepositoryTest ${SOURCE_CLIENT_REPOSITORY_FILES})
target_link_libraries (ClientRepositoryTest Biblioteka ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} -lboost_date_time)

#RentsManagerTest
set(SOURCE_RENTS_MANAGER_FILES test/master.cpp test/RentsManagerTest.cpp)
add_executable (RentsManagerTest ${SOURCE_RENTS_MANAGER_FILES})
target_link_libraries (RentsManagerTest Biblioteka ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} -lboost_date_time)

#FrequentClientTest
set(FREQUENT_CLIENT_FILES test/master.cpp test/FrequentClientTest.cpp)
add_executable (FrequentClientTest ${FREQUENT_CLIENT_FILES})
target_link_libraries (FrequentClientTest Biblioteka ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} -lboost_date_time)

#NormalClientTest
set(NORMAL_CLIENT_FILES test/master.cpp test/NormalClientTest.cpp)
add_executable (NormalClientTest ${NORMAL_CLIENT_FILES})
target_link_libraries (NormalClientTest Biblioteka ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} -lboost_date_time)

#RentsRepositoryTest
set(RENTS_REPOSITORY_FILES test/master.cpp test/RentsRepositoryTest.cpp)
add_executable (RentsRepositoryTest ${RENTS_REPOSITORY_FILES})
target_link_libraries (RentsRepositoryTest Biblioteka ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} -lboost_date_time)

#ClientManagerTest
set(CLIENT_MANAGER_FILES test/master.cpp test/ClientManagerTest.cpp)
add_executable (ClientManagerTest ${CLIENT_MANAGER_FILES})
target_link_libraries (ClientManagerTest Biblioteka ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} -lboost_date_time)

#VehicleManagerTest
set(VEHICLE_MANAGER_FILES test/master.cpp test/VehicleManagerTest.cpp)
add_executable (VehicleManagerTest ${VEHICLE_MANAGER_FILES})
target_link_libraries (VehicleManagerTest Biblioteka ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} -lboost_date_time)


add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
        ${CMAKE_CTEST_COMMAND} -C $<CONFIG> --verbose
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})

enable_testing()

add_test(CarTest CarTest)
add_test(MopeTest MopeTest --report_level=detailed --log_level=all --color_output=yes)
add_test(ClientTest ClientTest --report_level=detailed --log_level=all --color_output=yes)
add_test(BicycleTest BicycleTest --report_level=detailed --log_level=all --color_output=yes)
add_test(AddressTest AddressTest --report_level=detailed --log_level=all --color_output=yes)
add_test(VehicleRepositoryTest VehicleRepositoryTest --report_level=detailed --log_level=all --color_output=yes)
add_test(CurrentRentsRepositoryTest CurrentRentsRepositoryTest --report_level=detailed --log_level=all --color_output=yes)
add_test(ClientRepositoryTest ClientRepositoryTest --report_level=detailed --log_level=all --color_output=yes)
add_test(RentsManagerTest RentsManagerTest --report_level=detailed --log_level=all --color_output=yes)
add_test(FrequentClientTest FrequentClientTest --report_level=detailed --log_level=all --color_output=yes)
add_test(NormalClientTest NormalClientTest --report_level=detailed --log_level=all --color_output=yes)
add_test(RentsRepositoryTest RentsRepositoryTest --report_level=detailed --log_level=all --color_output=yes)
add_test(ClientManagerTest ClientManagerTest --report_level=detailed --log_level=all --color_output=yes)
add_test(VehicleManagerTest VehicleManagerTest --report_level=detailed --log_level=all --color_output=yes)
