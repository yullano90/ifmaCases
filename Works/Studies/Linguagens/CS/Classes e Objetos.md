> [![sistemas_de_informação](https://img.shields.io/badge/Sistemas_de_Informação-@IFMA-blue.svg)](url) </br>
> [![iulano_santos](https://img.shields.io/badge/Iulano_Santos-Backend%20Developer-orange.svg)](url) </br>

---

### • Classes e Objetos C#.


```cs
using System;

namespace Aula_House
{
    class Features_House
    {
        public static void Main(string[] args)
        {
            House house1 = new House();
            house1.adress = "Avenida Santos Dumont";
        }


        public class House
        {
            private string adress = "Avenida Brasil";
            private string color = "Blue";

            public House()
            {

            }

            public void TurnLigthsOn()
            {
                Console.WriteLine("Luzes Ligadas");
            }

            public void TurnLigthsOff()
            {
                Console.WriteLine("Luzes Desligadas");
            }
        }

        public BankAccount {
            private string personalName;
            private string balance;

        public Features_House()
        {

        }
        public void Deposit(decimal amout)
        {
            balance += amount;
        }

        public void ShowDetails()
        {
            Console.WriteLine($"{personalName} possui saldo de {balance}");
        }
    }
}


```