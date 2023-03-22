
#include "Txt.h"

#include <fstream>


namespace l1
{
	Txt::Txt()
		: m_buffer(nullptr),
		  m_size(0)
	{
	}

	Txt::Txt(const char* fileName)
		: Txt()
	{
		std::ifstream input(fileName);
		
		if (input)
		{
			input.seekg(0, std::ios_base::end);

			m_size = input.tellg();
			m_buffer = new char[m_size];

			input.seekg(0);
			input.read(m_buffer, m_size);

			input.close();
		}
	}

	Txt::Txt(const Txt& other)
	{
		if (other.size())
		{
			m_size = other.m_size;

			m_buffer = new char[this->m_size];

			for (int i = 0; i < m_size; ++i)
			{
				m_buffer[i] = other.m_buffer[i];
			}
		}
	}

	Txt::Txt(Txt&& other) noexcept
		: m_size(other.m_size),
		  m_buffer(other.m_buffer)
	{
		other.m_buffer = nullptr;
	}

	Txt& Txt::operator=(const Txt& other)
	{
		if (this != &other)
		{
			m_size = other.m_size;

			delete[] m_buffer;
			m_buffer = new char[this->m_size];

			for (int i = 0; i < m_size; ++i)
			{
				m_buffer[i] = other.m_buffer[i];
			}
		}

		return *this;
	}

	Txt& Txt::operator=(Txt&& other) noexcept
	{
		if (this != &other)
		{
			m_size = other.m_size;

			delete[] m_buffer;
			m_buffer = other.m_buffer;

			other.m_buffer = nullptr;
		}

		return *this;
	}

	Txt::~Txt()
	{
		if (m_buffer)
		{
			delete[] m_buffer;
			m_buffer = nullptr;
		}
	}

	size_t Txt::size() const
	{
		return m_size;
	}

}

