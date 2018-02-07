cmake_minimum_required(VERSION 3.4)

project(Program)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
find_package(Qt5Widgets)

#ustaw zbior plików zrodlowych projektu
set(SOURCE_FILES
        src/main.cpp
	modules/newForm/newForm.cpp
	modules/newForm/newForm.h

	modules/mainWindow/mainWindow.cpp
	modules/mainWindow/mainWindow.h

	modules/Clients/Clients.cpp
	modules/Clients/Clients.h

	modules/ClientEditForm/ClientEditForm.cpp
	modules/ClientEditForm/ClientEditForm.h

	modules/NewRent/NewRent.cpp
	modules/NewRent/NewRent.h

	modules/NewVehicle/NewCar/NewCar.cpp
	modules/NewVehicle/NewCar/NewCar.h

	modules/NewVehicle/NewBicycle/NewBicycle.cpp
	modules/NewVehicle/NewBicycle/NewBicycle.h

	modules/NewVehicle/NewMope/NewMope.cpp
	modules/NewVehicle/NewMope/NewMope.h

	modules/Vehicles/Vehicles.cpp
	modules/Vehicles/Vehicles.h

	modules/ArchivedRents/ArchivedRents.cpp
	modules/ArchivedRents/ArchivedRents.h

	modules/Serialization/ClientSerialization.cpp
	modules/QtAdapters/ClientQtAdapter/ClientQtAdapter.cpp
        )
#wlacz wskazane pliki do programu wykonywalnego Program
add_executable(Program ${SOURCE_FILES})

#Dolacz POBILibrary
target_link_libraries(Program Biblioteka Qt5::Widgets -lboost_date_time)

#dalacz pliki naglowkowe include projektu glownego
target_include_directories(Program PUBLIC include)
