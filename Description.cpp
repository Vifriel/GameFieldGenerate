#include "Description.h"

// ���������� ������������

void Description::setGreeting()
{
	this->greeting.clear();
	this->greeting.push_back("����� ���������� � ���� TestRPGConsoleGame, ��� �������� ������� ���������� ����!"); 
	// ��������, ��� ����� �������� �������� ������� � ���� string ���������� � �������� ����, ���� �� ������ ���������.		???
	this->greeting.push_back("�������� ����������������!");
}

void Description::setHeadDescription()
{
	this->headDescription.clear();
	this->headDescription.push_back("���� ���� - ������ ���������� ��������� ���������� �� �����, ������� �������� ���� � ���������� ���� ��� � �����! *");
	this->headDescription.push_back("\n");
	this->headDescription.push_back("\t����������� �������� �� �����: ");
	this->headDescription.push_back(" P - �������������� ������ (Player)");
	this->headDescription.push_back("\"  \" - ��������� ��� �������, ������ ������ ����");
	this->headDescription.push_back("@@ - ������������ �����");
	this->headDescription.push_back("[\\ - ���� �� �������");
	this->headDescription.push_back("/] - ����� � ������");
	this->headDescription.push_back(" O - ����������� ������");
	this->headDescription.push_back("SL - �������� �����, ��������������� �������� �� ���������. ������� ���� ������.");
	this->headDescription.push_back("CH - ������");
	this->headDescription.push_back(" K - ����");
	this->headDescription.push_back("PL - ������ �� ��������� ��������� ������ ������");

	// ������� ��������
	this->headDescription.push_back(" M - ������, ������������� ����");
	this->headDescription.push_back("MM - ������, ��� - ��������"); // ����� ��������� (��) 3. ��������� ��, ������� ������ ������, �������� ������� �� ���������,
	// +1 - ����������, +2 - ���������, +3 - �������, ���� - ���������� �������
	this->headDescription.push_back("GW - ������, ��� - ������-����"); // �� 1
	this->headDescription.push_back("GS - ������, ��� - ������-�����"); // �� 2
	this->headDescription.push_back("GB - ������, ��� - ������-����"); // �� 3
	this->headDescription.push_back(" S - ������, ��� - ������"); // �� 1
	this->headDescription.push_back("SA - ������, ��� - ������ - ������ "); // �� 2
	this->headDescription.push_back("SL - ������, ��� - ������-���"); // �� 7
	this->headDescription.push_back("CP - ������, ������"); // �� 10
	this->headDescription.push_back("DN - ������, ������"); // �� 13
	this->headDescription.push_back("\n");
	this->headDescription.push_back("*���, �� ������� ����, �� ����� ������� ������.");
}

void Description::setBuffer()
{
	this->buffer.clear();
	this->buffer.push_back("/////////////////////////////////////////////////////////");
	this->buffer.push_back("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||");
	this->buffer.push_back("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");
}

void Description::setGeneralHint()
{
	this->generalHint.clear();
	//���������� ����������
	this->generalHint.push_back("���� ������������ ��� �������� ������ � ������� ��������. ��� ������ ������ ���� ������ ���� ����������.");
	this->generalHint.push_back("� ��� ���� ������ � ������� ��������� ����������. ����������� ���� ������� �� ������� ���������� ����������.");
	this->generalHint.push_back("���� ���, �� ���������, 3 ��������. �������, �� ��������� ��������, �������� ��� � ����� ��������.");
	this->generalHint.push_back("\"������\" - ���������� ������� �������������� ��������� (�� ���������). �� ������� ��������.");
	this->generalHint.push_back("\"���������\" - ���������� ��������� ���������. �� ������� ��������.");
	this->generalHint.push_back("\"������\" - ������������� �� ������ ������, ���� ��� ��������.");
	this->generalHint.push_back("\"�����\" - ������������� �� ������ �����, ���� ��� ��������.");
	this->generalHint.push_back("\"�����\" - ������������� �� ������ �����, ���� ��� ��������.");
	this->generalHint.push_back("\"����\" - ������������� �� ������ ����, ���� ��� ��������.");
	this->generalHint.push_back("\"�����\" - ������� ���������� �������� �������. ���� ��������� ������ ������������, ������ ���������� �������� ���� �� �������� � �����, \
���� �� ������ ���������.");
	this->generalHint.push_back("\"*�������� ����������*\" - ���������� ���������� �� ����, ���� �������, �� ����������, ���� ���. ������ ���������� ������ �������������� \
���������� ��������.");
	this->generalHint.push_back("\"������\" - �������� ����� ����, ������ ���������� �������");
	this->generalHint.push_back("\"�����\" - ����� �� ����");
	this->generalHint.push_back("\"������?\" - ����� ���������� � ���� ������� ����������. �� ������� ��������.");
	this->generalHint.push_back("\"�����?\" - ����� ���������� � ������������ ������. �� ������� ��������. ��� ���������� � ��������� ������ ��������� ����������� \
\"������\".");
	this->generalHint.push_back("\"*�������� �����?*\" - ����� ���������� � ���������� �����. �� ������� ��������.");
	this->generalHint.push_back("\"��������\" - ������������� ���������� ������ ��� ��������� ���������� � ������������ �������� ��� ���������. �� ������� ��������.");
	this->generalHint.push_back("\"����������?\" - ��������� ���������� � ������������ �����������. �� ������� ��������.");
	this->generalHint.push_back("\"������������ *� ��������*\" - ������������ ������������ ������� �� ���������. �������������� ���������� �������� ��� ������� ��������.");
	this->generalHint.push_back("\"������������\" - ������������ ������.");
}

void Description::setValediction()
{
	this->valediction.clear();
	this->valediction.push_back("������� �� ��������� �����! �������, ����������� �������� ��������! ����� � �� ����� ������!");
}

void Description::outputGreeting() const
{
	for (auto element : this->greeting)
	{
		std::cout << element << '\n';
	}
}

void Description::outputBuffer() const
{
	for (auto element : this->buffer)
	{
		std::cout << element << '\n';
	}
}

void Description::outputGeneralHint() const
{
	for (auto element : this->generalHint)
	{
		std::cout << element << '\n';
	}
}

void Description::outputHeadDescription() const
{
	for (auto element : this->headDescription)
	{
		std::cout << element << '\n';
	}
}

void Description::outputValediction() const
{
	for (auto element : this->valediction)
	{
		std::cout << element << '\n';
	}
}