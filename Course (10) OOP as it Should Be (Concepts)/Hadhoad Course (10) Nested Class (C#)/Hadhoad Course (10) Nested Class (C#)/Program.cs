using System.Runtime.InteropServices;
using System.Security.AccessControl;

namespace Hadhoad_Course__10__Nested_Class__C__
{
    public class clsPerson
    {
        private clsAddress _addressDetails { get; set; }
        public string FullName { get; set; }

        public clsPerson(string fullName,
        string addressLine1,
        string addressLine2,
        string city,
        string country)
        {
            FullName = fullName;
            _addressDetails = new clsAddress(addressLine1, addressLine2, city, country);
        }

        public class clsAddress
        {
            string _addressLine1;
            string _addressLine2;
            string _city;
            string _country;

            public clsAddress(string addressLine1, 
                string addressLine2,
                string city,
                string country)
            {
                _addressLine1 = addressLine1;
                _addressLine2 = addressLine2;
                _city = city;
                _country = country;
            }

            public void setAddressLine1(string AddressLine1)
            {
                _addressLine1 = AddressLine1;
            }
            public string AddressLine1()
            {
                return _addressLine1;
            }
            public void setAddressLine2(string AddressLine2)
            {
                _addressLine2 = AddressLine2;
            }

            public string AddressLine2()
            {
                return _addressLine2;
            }
            public void setCity(string City)
            {
                _city = City;
            }
            public string City()
            {
                return _city;
            }
            public void setCountry(string Country)
            {
                _country = Country;
            }
            public string Country()
            {
                return _country;
            }

            public void Print()
            {
                Console.WriteLine("\nAddress:\n");
                Console.WriteLine(AddressLine1());
                Console.WriteLine(AddressLine2());
                Console.WriteLine(City());
                Console.WriteLine(Country());
            }
        }


        public void PrintAddressDetails()
        {
            _addressDetails.Print();
        }

        public void PrintFullName()
        {
            Console.WriteLine(FullName);
        }
    }

    internal class Program
    {
        static void Main(string[] args)
        {
            clsPerson Person = new clsPerson("Ahmed hosny", 
                "Hissan Hamad",
                "Building 10",
                "Dekernes",
                "Egypt");

            clsPerson.clsAddress Address = new clsPerson.clsAddress("Hissan Hamad",
                "Building 10",
                "Dekernes",
                "Egypt");


            Person.PrintFullName();
            Person.PrintAddressDetails();

            Address.Print();

            
        }
    }
}
