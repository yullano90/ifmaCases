using System;

namespace ConsoleApp
{
    class Program
    {
        static void Main()
        {
            Employee cadastro = new Employee();
            House house = new House();

            house.ShowHouseDetails();

            cadastro.DataUSer();
            Console.Read();

            BankAccount bankAccount = new BankAccount();
            bankAccount.personalName = "Yullano Santos";
            bankAccount.Deposit(1000);
            bankAccount.ShowDetails();
            Console.Read();

            ForeachSample foreachSample = new ForeachSample();
            foreachSample.ReadList();
            Console.Read();
        }
    }

    public class House
    {
        string endereco = "Avenida Paulista";
        int numerocasa = 22;
        bool status = false;

        public House()
        {

        }

        public void StatusImóvel()
        {
            if (this.status == true)
            {
                Console.Write("Imóvel Vendido");
            }
            else
            {
                Console.Write("Imóvel Disponível");
            }
        }

        public void ShowHouseDetails()
        {
            Console.WriteLine($" \n ========= Endereço ========= \n Endereço: {endereco} \n numero {numerocasa}");
            StatusImóvel();

        }
    }

    public class Employee
    {
        string name = "Yullano";
        int idade = 31;
        string escolaridade = "Superior Completo";
        string curso = "Sistemas de Informação";
        string ies = "IFMA Monte Castelo";

        public Employee()
        {

        }

        public void DataUSer()
        {
            Console.WriteLine($" \n\n========= Colaborador ========= \n Nome: {name} \n Idade: {idade} \n Escolaridade: {escolaridade} \n Curso: {curso} \n IES: {ies}");
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
            Console.WriteLine($" \n ========= CONTA ========= \n Saldo: {balance:C2}");
        }
    }

    public class ForeachSample
    {
        public void ReadList()
        {
            string[] nomes = {"Gabriel", "Davi", "Daniel", "Isaque" };

            Console.Write("\n========= FILHOS =========\n ");
            foreach (string nome in nomes)
            {
                Console.WriteLine(nome);
            }
        }
    }

}


