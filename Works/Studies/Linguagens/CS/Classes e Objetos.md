> [![sistemas_de_informação](https://img.shields.io/badge/Sistemas_de_Informação-@IFMA-blue.svg)](url) </br>

---
https://www.jdoodle.com/compile-c-sharp-online/

### • Classes e Objetos C#.


```cs
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace WebApp
{
    public class Program
    {
        public static void Main(string[] args)
        {
            BankAccount bankAccount = new BankAccount();
            bankAccount.personalName = "Yullano Santos";
            bankAccount.Deposit(1000);
            bankAccount.ShowDetails();
        }
    }

    public class House
    {
        public string Adress;
        public string Color;

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

    public class BankAccount
    {
        public string personalName;
        public string balance;

        public BankAccount()
        {

        }

        public void Deposit(decimal amount)
        {
            balance += amount;
        }

        public void ShowDetails()
        {
            Console.WriteLine($"{personalName} possui saldo de {balance:C2}");
        }
    }
}

```