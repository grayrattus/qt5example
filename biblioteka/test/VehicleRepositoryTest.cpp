#include <boost/test/unit_test.hpp>
#include <VehicleRepository.h>
using namespace std;

BOOST_AUTO_TEST_CASE(PodstawowyKonstruktor) {
    VehicleRepository repozytorium;
    auto vehicles =repozytorium.getAll();
    BOOST_CHECK_EQUAL(vehicles.size(), 10);
}
