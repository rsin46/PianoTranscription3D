# pragma once
# include "..\..\Model\MidiParserLib\IFileParser.h"

namespace Model
{
	namespace MidiParser
	{
		class FileParser_Mock : public IFileParser
		{
			const int32_t UNUSED = NULL;	// four padding bytes
			std::ifstream inputFile_;
		public:
			explicit FileParser_Mock(const char* fileName) :
				IFileParser(),
				inputFile_(fileName, std::ifstream::in)
			{}
			virtual ~FileParser_Mock() override final = default;
		private:
			virtual int GetBytesRemained_impl() const override final;
			virtual void SetBytesRemained_impl(int) const override final;

			virtual int PeekByte_impl() override final;
			virtual char ReadByte_impl() override final;
			virtual void ReadData_impl(char*, std::streamsize) override final;
			virtual void SkipData_impl(std::streamoff offset) override final;

			virtual unsigned ReadInverse_impl(unsigned, bool) override final;
			virtual unsigned ReadVarLenFormat_impl() override final;
		};

		uint32_t ReadWord(std::shared_ptr<FileParser_Mock>);	// Word = 4 bytes!!!
		uint16_t ReadDWord(std::shared_ptr<FileParser_Mock>);	// DWord = 2 bytes!!!
	}
}