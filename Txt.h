#pragma once


namespace l1
{

	class Txt
	{
	public:
		Txt();
		Txt(const char* fileName);
		
		Txt(const Txt& other);
		Txt(Txt&& other) noexcept;

		~Txt();

		Txt& operator=(const Txt& other);
		Txt& operator=(Txt&& other) noexcept;

		size_t size() const;


	private:
		char* m_buffer;
		int m_size;
	};

}

