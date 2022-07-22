using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;


namespace ConsoleApp
{
    public class Program
    {
        this.private DeleteAllComments();
        public static void Main(string[] args)
        {
            House house = new House();
            house.TurnLigthsOff();

            BankAccount bankAccount = new BankAccount();
            bankAccount.personalName = "Yullano Santos";
            bankAccount.Deposit(1000);
            bankAccount.ShowDetails();

            ForeachSample foreachSample = new ForeachSample();
            foreachSample.ReadList();
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

    public class ForeachSample //Teste para remover commits no head
    {
        public void ReadList()
        {
            string[] nomes = { "Yullano", "Gabriel", "Davi", "Daniel" };

            foreach (string nome in nomes)
            {
                Console.WriteLine(nome);
            }
        }
    }
}

