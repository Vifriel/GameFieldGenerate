#pragma once

#include <iostream>
#include <Windows.h>
#include <vector>

class Description
{
public:
	// ����� ���������
	void outputGreeting() const;
	void outputHeadDescription() const;
	void outputGeneralHint() const;
	void outputValediction() const;
	void outputBuffer() const;
	// �������������� ������ ����������� ������������, ��������� ��������� �� ��������, �� ����������� �� �������������
	explicit Description()
	{
		//std::cout << "��������� ����� ��������";
		setGreeting();
		setHeadDescription();
		setGeneralHint();
		setValediction();
		setBuffer();
		//std::cout << "��������� ������";
	}

private:
	std::vector<std::string> greeting;			// �����������
	std::vector<std::string> headDescription;	// ����� ������ ���������� ��� ������ ����
	std::vector<std::string> generalHint;		// ��������� �� ����������� ��������
	std::vector<std::string> valediction;		// ���������� ��������� ��� ���������� ���������
	std::vector<std::string> buffer;			// ��������� ��� ��������������� ����

	// ����������� ���������
	void setGreeting();
	void setHeadDescription();
	void setGeneralHint();
	void setValediction();
	void setBuffer();

	// ������� ����� ����������� ������������� � �������������
	Description(const Description&) {}
	const Description& operator= (const Description&) {}
};

