#ifndef YAPOG_DATABASESTREAM_HPP
# define YAPOG_DATABASESTREAM_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/IO/IWriter.hpp"
# include "YAPOG/System/IO/IReader.hpp"
# include "pgstream/pgstream.hpp"

namespace yap
{
  class YAPOG_LIB DatabaseStream 
    : public IWriter
    , public IReader
  {
    DISALLOW_COPY(DatabaseStream);
  public:
    DatabaseStream (
      const yap::String& query, 
      pgs::pg_cnx& databaseConnection);

    /// @name IWriter members.
    /// @{
    virtual void Accept (IWriterVisitor& visitor);
    virtual void Accept (IWriterConstVisitor& visitor) const;

    virtual void Write (const String& value);
    virtual void Write (const String& name, const String& value);

    virtual void Write (const bool& value);
    virtual void Write (const String& name, const bool& value);

    virtual void Write (const char& value);
    virtual void Write (const String& name, const char& value);

    virtual void Write (const uchar& value);
    virtual void Write (const String& name, const uchar& value);

    virtual void Write (const Int16& value);
    virtual void Write (const String& name, const Int16& value);

    virtual void Write (const UInt16& value);
    virtual void Write (const String& name, const UInt16& value);

    virtual void Write (const int& value);
    virtual void Write (const String& name, const int& value);

    virtual void Write (const uint& value);
    virtual void Write (const String& name, const uint& value);

    virtual void Write (const Int64& value);
    virtual void Write (const String& name, const Int64& value);

    virtual void Write (const UInt64& value);
    virtual void Write (const String& name, const UInt64& value);

    virtual void Write (const float& value);
    virtual void Write (const String& name, const float& value);

    virtual void Write (const double& value);
    virtual void Write (const String& name, const double& value);

    virtual void Write (const Vector2& value);
    virtual void Write (const String& name, const Vector2& value);

    virtual void Write (const ID& value);
    virtual void Write (const String& name, const ID& value);
    /// @}

    /// @name IReader members.
    /// @{
    virtual void Accept (IReaderVisitor& visitor);
    virtual void Accept (IReaderConstVisitor& visitor) const;

    virtual String ReadString ();
    virtual String ReadString (const String& name);

    virtual bool ReadBool ();
    virtual bool ReadBool (const String& name);

    virtual char ReadChar ();
    virtual char ReadChar (const String& name);

    virtual uchar ReadUChar ();
    virtual uchar ReadUChar (const String& name);

    virtual Int16 ReadInt16 ();
    virtual Int16 ReadInt16 (const String& name);

    virtual UInt16 ReadUInt16 ();
    virtual UInt16 ReadUInt16 (const String& name);

    virtual int ReadInt ();
    virtual int ReadInt (const String& name);

    virtual uint ReadUInt ();
    virtual uint ReadUInt (const String& name);

    virtual Int64 ReadInt64 ();
    virtual Int64 ReadInt64 (const String& name);

    virtual UInt64 ReadUInt64 ();
    virtual UInt64 ReadUInt64 (const String& name);

    virtual float ReadFloat ();
    virtual float ReadFloat (const String& name);

    virtual double ReadDouble ();
    virtual double ReadDouble (const String& name);

    virtual Vector2 ReadVector2 ();
    virtual Vector2 ReadVector2 (const String& name);

    virtual ID ReadID ();
    virtual ID ReadID (const String& name);
    /// @}

    /// @name pg_stream methods.
    /// @{ 
    int EndOfStream ();
    int AffectedRows () const;
    bool ReturnValueIsEmpty () const;
    /// @}

  private:
    template <typename T>
    void WriteData (const T& data);

    template <typename T>
    T ReadData ();

    pgs::pg_stream pgStream_;
  };
} // namespace yap

# include "YAPOG/Database/DatabaseStream.hxx"

#endif // YAPOG_DATABASESTREAM_HPP
