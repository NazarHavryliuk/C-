#include "FormUser.h"

System::Void SportCO::FormUser::button_download_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ connectionString = "provider=Microsoft.ACE.OLEDB.12.0;Data Source=DatabaseUser.accdb";
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    dbConnection->Open();
    String^ query = "SELECT * From [TableUser]";
    OleDbCommand^ dbComabd = gcnew OleDbCommand(query, dbConnection);
    OleDbDataReader^ dbReader = dbComabd->ExecuteReader();

    if (dbReader->HasRows == false)
    {
        MessageBox::Show("Помилка зчитування данних!", "Помилка!");
    }
    else
    {
        while (dbReader->Read())
        {
            dataGridView1->Rows->Add(dbReader["id"], dbReader["firstname"], dbReader["lastname"]);
        }
    }
    dbReader->Close();
    dbConnection->Close();
    return System::Void();
}

System::Void SportCO::FormUser::button_add_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (dataGridView1->SelectedRows->Count != 1)
    {
        MessageBox::Show("Виберіть одну стрічку щоб добавити!", "Увага!");
        return;
    }
    int index = dataGridView1->SelectedRows[0]->Index;
    if (dataGridView1->Rows[index]->Cells[0]->Value == nullptr ||
        dataGridView1->Rows[index]->Cells[1]->Value == nullptr ||
        dataGridView1->Rows[index]->Cells[2]->Value == nullptr)
    {
        MessageBox::Show("Не всі дані введені!", "Увага!");
        return;
    }

    // Припускаючи, що id - ціле число, а firstname та lastname - рядки
    int id = Convert::ToInt32(dataGridView1->Rows[index]->Cells[0]->Value);
    String^ firstname = dataGridView1->Rows[index]->Cells[1]->Value->ToString();
    String^ lastname = dataGridView1->Rows[index]->Cells[2]->Value->ToString();

    String^ connectionString = "provider=Microsoft.ACE.OLEDB.12.0;Data Source=D:\\Visual studio\\C\\SportCO\\SportCO\\DatabaseUser.accdb";
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    try
    {
        dbConnection->Open();
        String^ query = "INSERT INTO [TableUser] VALUES(" + id.ToString() + ", '" + firstname + "', '" + lastname + "');";  // Додано крапку з комою
        OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection);

        int rowsAffected = dbComand->ExecuteNonQuery();

        if (rowsAffected != 1)
        {
            MessageBox::Show("Помилка виконання запиту!", "Помилка!");
        }
        else
        {
            MessageBox::Show("Данні додані!", "Готово!");
        }
    }
    catch (OleDbException^ ex)
    {
        MessageBox::Show("Помилка підключення до бази даних: " + ex->Message, "Помилка!");
    }
    finally
    {
        if (dbConnection->State == ConnectionState::Open)
        {
            dbConnection->Close();
        }
    }

    return System::Void();
}

System::Void SportCO::FormUser::button_update_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (dataGridView1->SelectedRows->Count != 1)
    {
        MessageBox::Show("Виберіть одну стрічку щоб оновити!", "Увага!");
        return;
    }
    int index = dataGridView1->SelectedRows[0]->Index;
    if (dataGridView1->Rows[index]->Cells[0]->Value == nullptr ||
        dataGridView1->Rows[index]->Cells[1]->Value == nullptr ||
        dataGridView1->Rows[index]->Cells[2]->Value == nullptr)
    {
        MessageBox::Show("Не всі дані введені!", "Увага!");
        return;
    }

    // Припускаючи, що id - ціле число, а firstname та lastname - рядки
    int id = Convert::ToInt32(dataGridView1->Rows[index]->Cells[0]->Value);
    String^ firstname = dataGridView1->Rows[index]->Cells[1]->Value->ToString();
    String^ lastname = dataGridView1->Rows[index]->Cells[2]->Value->ToString();

    String^ connectionString = "provider=Microsoft.ACE.OLEDB.12.0;Data Source=D:\\Visual studio\\C\\SportCO\\SportCO\\DatabaseUser.accdb";
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    try
    {
        dbConnection->Open();
        String^ query = "UPDATE [TableUser] SET firstname='" + firstname + "', lastname ='" + lastname + "' WHERE id = " + id.ToString();
        OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection);

        int rowsAffected = dbComand->ExecuteNonQuery();

        if (rowsAffected != 1)
        {
            MessageBox::Show("Помилка виконання запиту!", "Помилка!");
        }
        else
        {
            MessageBox::Show("Дані оновлені!", "Готово!");
        }
    }
    catch (OleDbException^ ex)
    {
        MessageBox::Show("Помилка підключення до бази даних: " + ex->Message, "Помилка!");
    }
    finally
    {
        if (dbConnection->State == ConnectionState::Open)
        {
            dbConnection->Close();
        }
    }

    return System::Void();
}

System::Void SportCO::FormUser::button_delete_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (dataGridView1->SelectedRows->Count != 1)
    {
        MessageBox::Show("Виберіть одну стрічку щоб оновити!", "Увага!");
        return;
    }
    int index = dataGridView1->SelectedRows[0]->Index;
    if (dataGridView1->Rows[index]->Cells[0]->Value == nullptr)
    {
        MessageBox::Show("Не всі дані введені!", "Увага!");
        return;
    }

    // Припускаючи, що id - ціле число, а firstname та lastname - рядки
    int id = Convert::ToInt32(dataGridView1->Rows[index]->Cells[0]->Value);

    String^ connectionString = "provider=Microsoft.ACE.OLEDB.12.0;Data Source=D:\\Visual studio\\C\\SportCO\\SportCO\\DatabaseUser.accdb";
    OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

    try
    {
        dbConnection->Open();
        String^ query = "DELETE FROM [TableUser] WHERE id = " + id.ToString();
        OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection);

        int rowsAffected = dbComand->ExecuteNonQuery();

        if (rowsAffected != 1)
        {
            MessageBox::Show("Помилка виконання запиту!", "Помилка!");
        }
        else
        {
            MessageBox::Show("Дані видалні!", "Готово!");
            dataGridView1->Rows->RemoveAt(index);
        }
    }
    catch (OleDbException^ ex)
    {
        MessageBox::Show("Помилка підключення до бази даних: " + ex->Message, "Помилка!");
    }
    finally
    {
        if (dbConnection->State == ConnectionState::Open)
        {
            dbConnection->Close();
        }
    }

    return System::Void();
}
