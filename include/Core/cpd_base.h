#ifndef CPD_BASE_H
#define CPD_BASE_H

namespace cpd
{
	template <class T>
	class CPDBase
	{
	public:
		CPDBase();
		virtual ~CPDBase();

		void setInputData(T* const model, T* const data);
		
		void apply();
		virtual void intialization() = 0;
		virtual void em() = 0;
		virtual void align() = 0;

	private:
		T* _model;
		T* _data;
	};
}

#endif