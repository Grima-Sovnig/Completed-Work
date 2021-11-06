import java.util.Iterator;
import java.util.TreeSet;

public class MapSet<T>{

    private TreeSet<KeyValuePair<T>> collection;

    public MapSet(){
        collection = new TreeSet<>();
    }

    /**
     * Create and add a KeyValuePair object to the collection
     * @param key
     * @param value
     * @return true if the element is successfully added
     */
    public boolean add(String key, T value){
        KeyValuePair<T> obj = new KeyValuePair<>(key, value);
        if(collection.add(obj))
        {
            return true;
        }
        return false;
    }

    /**
     * Return the "Value" part of a KeyValuePair for the given object indexed by "key"
     * @param key
     * @return
     */
    public T getValue(String key){
        for(KeyValuePair<T> obj: collection)
        {
            if(obj.getKey() == key)
            {
                return obj.getValue();
            }
        }
        return null;
    }

    /**
     * Return true if a KeyValuePair object indexed by the input "key" exists in the collection
     * @param key
     * @return
     */
    public boolean contains(String key){
        for(KeyValuePair<T> obj: collection)
        {
            if(obj.getKey() == key)
            {
                return true;
            }
        }
        return false;
    }

    /**
     * Return the iterator for the embedded collection
     * @return
     */
    public Iterator<KeyValuePair<T>> getIterator(){

        return collection.iterator();
    }

}
