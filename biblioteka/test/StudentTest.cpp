#include <boost/test/unit_test.hpp>

#include "Student.h"

BOOST_AUTO_TEST_SUITE(StudentSuiteCorrect)

BOOST_AUTO_TEST_CASE(StudentFirstNameCase) {
    Student student("Adam", "Slodowy");
    BOOST_REQUIRE_EQUAL(student.getFirstName(), "Adam");
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(StudentSuiteFailure)

BOOST_AUTO_TEST_CASE(StudentFirstNameRequire) {
    Student student("Adam", "Slodowy");
    BOOST_REQUIRE_EQUAL(student.getFirstName(), "Blad"); //fatal error - end test case
    BOOST_REQUIRE_EQUAL(student.getFirstName(), "Adam"); //not invoked due to previous fatal error
}

BOOST_AUTO_TEST_CASE(StudentFirstNameCheck) {
    Student student("Adam", "Slodowy");
    BOOST_CHECK_EQUAL(student.getFirstName(), "Blad"); //error - continue testing
    BOOST_CHECK_EQUAL(student.getFirstName(), "Adam");
}

BOOST_AUTO_TEST_SUITE_END()
