
/**********************************************************************
* class CBitmapDisplay
* Abstract class for a bitmap display
***********************************************************************/
interface CBitmapDisplay
{
	virtual ~CBitmapDisplay() = 0 {}

  virtual int Width() const = 0;
  virtual int Height() const = 0;

  virtual void Clear() = 0;
	virtual void WriteBit(int ix, int iy, bool blBit) = 0;
	virtual void Refresh() = 0;
};
