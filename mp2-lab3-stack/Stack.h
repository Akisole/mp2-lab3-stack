template <class T>
class TStack {
	int maxsize;
	int size;
	T* array;
public:
	TStack (int _msize=200) {
		array=new T[_msize];
		maxsize=_msize;
		size=0;
	}
};