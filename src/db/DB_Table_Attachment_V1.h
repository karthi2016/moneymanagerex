// -*- C++ -*-
//=============================================================================
/**
 *      Copyright (c) 2013,2014 Guan Lisheng (guanlisheng@gmail.com)
 *
 *      @file
 *
 *      @author [sqlite2cpp.py]
 *
 *      @brief
 *
 *      Revision History:
 *          AUTO GENERATED at 2014-04-13 11:13:53.338000.
 *          DO NOT EDIT!
 */
//=============================================================================

#ifndef DB_TABLE_ATTACHMENT_V1_H
#define DB_TABLE_ATTACHMENT_V1_H

#include "DB_Table.h"

struct DB_Table_ATTACHMENT_V1 : public DB_Table
{
    struct Data;
    typedef DB_Table_ATTACHMENT_V1 Self;
    /** A container to hold list of Data records for the table*/
    struct Data_Set : public std::vector<Self::Data>
    {
        std::string to_json() const
        {
            json::Array a;
            for (const auto & item: *this)
            {
                json::Object o;
                item.to_json(o);
                a.Insert(o);
            }
            std::stringstream ss;
            json::Writer::Write(a, ss);
            return ss.str();
        }
    };
    /** A container to hold a list of Data record pointers for the table in memory*/
    typedef std::vector<Self::Data*> Cache;
    Cache cache_;

    /** Destructor: clears any data records stored in memory */
    ~DB_Table_ATTACHMENT_V1() 
    {
        destroy_cache();
    }
    
    /** Show table statistics*/
	void show_statistics()
	{
		size_t cache_size = this->cache_.size();
#ifdef _WIN64
        wxLogDebug("%s : (cache %llu, hit %llu, miss %llu, skip %llu)", this->name(), cache_size, this->hit_, this->miss_, this->skip_);
#else
        wxLogDebug("%s : (cache %lu, hit %lu, miss %lu, skip %lu)", this->name(), cache_size, this->hit_, this->miss_, this->skip_);
#endif
	}
	 
    /** Removes all records stored in memory (cache) for the table*/ 
    void destroy_cache()
    {
        std::for_each(cache_.begin(), cache_.end(), std::mem_fun(&Data::destroy));
        cache_.clear();
    }

    /** Creates the database table if the table does not exist*/
    bool ensure(wxSQLite3Database* db)
    {
        if (!exists(db))
		{
			try
			{
				db->ExecuteUpdate("CREATE TABLE ATTACHMENT_V1 (ATTACHMENTID INTEGER NOT NULL PRIMARY KEY, REFTYPE TEXT NOT NULL, REFID INTEGER NOT NULL, DESCRIPTION TEXT COLLATE NOCASE, FILENAME TEXT NOT NULL COLLATE NOCASE )");
			}
			catch(const wxSQLite3Exception &e) 
			{ 
				wxLogError("ATTACHMENT_V1: Exception %s", e.GetMessage().c_str());
				return false;
			}
		}

        this->ensure_index(db);

        return true;
    }

    bool ensure_index(wxSQLite3Database* db)
    {
        try
        {
            db->ExecuteUpdate("CREATE INDEX IF NOT EXISTS IDX_ATTACHMENT_REF ON ATTACHMENT_V1 (REFTYPE, REFID)");
        }
        catch(const wxSQLite3Exception &e) 
        { 
            wxLogError("ATTACHMENT_V1: Exception %s", e.GetMessage().c_str());
            return false;
        }

        return true;
    }

    struct ATTACHMENTID : public DB_Column<int>
    { 
        static wxString name() { return "ATTACHMENTID"; } 
        ATTACHMENTID(const int &v, OP op = EQUAL): DB_Column<int>(v, op) {}
    };
    struct REFTYPE : public DB_Column<wxString>
    { 
        static wxString name() { return "REFTYPE"; } 
        REFTYPE(const wxString &v, OP op = EQUAL): DB_Column<wxString>(v, op) {}
    };
    struct REFID : public DB_Column<int>
    { 
        static wxString name() { return "REFID"; } 
        REFID(const int &v, OP op = EQUAL): DB_Column<int>(v, op) {}
    };
    struct DESCRIPTION : public DB_Column<wxString>
    { 
        static wxString name() { return "DESCRIPTION"; } 
        DESCRIPTION(const wxString &v, OP op = EQUAL): DB_Column<wxString>(v, op) {}
    };
    struct FILENAME : public DB_Column<wxString>
    { 
        static wxString name() { return "FILENAME"; } 
        FILENAME(const wxString &v, OP op = EQUAL): DB_Column<wxString>(v, op) {}
    };
    typedef ATTACHMENTID PRIMARY;
    enum COLUMN
    {
        COL_ATTACHMENTID = 0
        , COL_REFTYPE = 1
        , COL_REFID = 2
        , COL_DESCRIPTION = 3
        , COL_FILENAME = 4
    };

    /** Returns the column name as a string*/
    static wxString column_to_name(COLUMN col)
    {
        switch(col)
        {
            case COL_ATTACHMENTID: return "ATTACHMENTID";
            case COL_REFTYPE: return "REFTYPE";
            case COL_REFID: return "REFID";
            case COL_DESCRIPTION: return "DESCRIPTION";
            case COL_FILENAME: return "FILENAME";
            default: break;
        }
        
        return "UNKNOWN";
    }

    /** Returns the comumn number from the given column name*/
    static COLUMN name_to_column(const wxString& name)
    {
        if ("ATTACHMENTID" == name) return COL_ATTACHMENTID;
        else if ("REFTYPE" == name) return COL_REFTYPE;
        else if ("REFID" == name) return COL_REFID;
        else if ("DESCRIPTION" == name) return COL_DESCRIPTION;
        else if ("FILENAME" == name) return COL_FILENAME;

        return COLUMN(-1);
    }
    
    /** Data is a single record in the database table*/
    struct Data
    {
        friend struct DB_Table_ATTACHMENT_V1;
        /** This is a instance pointer to itself in memory. */
        Self* view_;
    
        int ATTACHMENTID;//  primay key
        wxString REFTYPE;
        int REFID;
        wxString DESCRIPTION;
        wxString FILENAME;
        int id() const { return ATTACHMENTID; }
        void id(int id) { ATTACHMENTID = id; }
        bool operator < (const Data& r) const
        {
            return this->id() < r.id();
        }
        bool operator < (const Data* r) const
        {
            return this->id() < r->id();
        }

        Data(Self* view = 0) 
        {
            view_ = view;
        
            ATTACHMENTID = -1;
            REFID = -1;
        }

        Data(wxSQLite3ResultSet& q, Self* view = 0)
        {
            view_ = view;
        
            ATTACHMENTID = q.GetInt(0); // ATTACHMENTID
            REFTYPE = q.GetString(1); // REFTYPE
            REFID = q.GetInt(2); // REFID
            DESCRIPTION = q.GetString(3); // DESCRIPTION
            FILENAME = q.GetString(4); // FILENAME
        }

        wxString to_json() const
        {
            json::Object o;
            this->to_json(o);
            std::stringstream ss;
            json::Writer::Write(o, ss);
            return ss.str();
        }
        
        int to_json(json::Object& o) const
        {
            o["ATTACHMENTID"] = json::Number(this->ATTACHMENTID);
            o["REFTYPE"] = json::String(this->REFTYPE.ToStdString());
            o["REFID"] = json::Number(this->REFID);
            o["DESCRIPTION"] = json::String(this->DESCRIPTION.ToStdString());
            o["FILENAME"] = json::String(this->FILENAME.ToStdString());
            return 0;
        }
        row_t to_row_t() const
        {
            row_t row;
            row(L"ATTACHMENTID") = ATTACHMENTID;
            row(L"REFTYPE") = REFTYPE;
            row(L"REFID") = REFID;
            row(L"DESCRIPTION") = DESCRIPTION;
            row(L"FILENAME") = FILENAME;
            return row;
        }
        void to_template(html_template& t) const
        {
            t(L"ATTACHMENTID") = ATTACHMENTID;
            t(L"REFTYPE") = REFTYPE;
            t(L"REFID") = REFID;
            t(L"DESCRIPTION") = DESCRIPTION;
            t(L"FILENAME") = FILENAME;
        }

        /** Save the record instance in memory to the database. */
        bool save(wxSQLite3Database* db)
        {
            if (!view_ || !db) 
            {
                wxLogError("can not save ATTACHMENT_V1");
                return false;
            }

            return view_->save(this, db);
        }

        /** Remove the record instance from memory and the database. */
        bool remove(wxSQLite3Database* db)
        {
            if (!view_ || !db) 
            {
                wxLogError("can not remove ATTACHMENT_V1");
                return false;
            }
            
            return view_->remove(this, db);
        }

        void destroy() { delete this; }
    };

    enum
    {
        NUM_COLUMNS = 5
    };

    size_t num_columns() const { return NUM_COLUMNS; }

    /** Name of the table*/    
    wxString name() const { return "ATTACHMENT_V1"; }

    DB_Table_ATTACHMENT_V1() 
    {
        query_ = "SELECT * FROM ATTACHMENT_V1 ";
    }

    /** Create a new Data record and add to memory table (cache)*/
    Self::Data* create()
    {
        Self::Data* entity = new Self::Data(this);
        cache_.push_back(entity);
        return entity;
    }
    
    /** Create a copy of the Data record and add to memory table (cache)*/
    Self::Data* clone(const Data* e)
    {
        Self::Data* entity = create();
        *entity = *e;
        entity->id(-1);
        return entity;
    }

    /**
    * Saves the Data record to the database table.
    * Either create a new record or update the existing record.
    * Remove old record from the memory table (cache)
    */
    bool save(Self::Data* entity, wxSQLite3Database* db)
    {
        wxString sql = wxEmptyString;
        if (entity->id() <= 0) //  new & insert
        {
            sql = "INSERT INTO ATTACHMENT_V1(REFTYPE, REFID, DESCRIPTION, FILENAME) VALUES(?, ?, ?, ?)";
        }
        else
        {
            sql = "UPDATE ATTACHMENT_V1 SET REFTYPE = ?, REFID = ?, DESCRIPTION = ?, FILENAME = ? WHERE ATTACHMENTID = ?";
        }

        try
        {
            wxSQLite3Statement stmt = db->PrepareStatement(sql);

            stmt.Bind(1, entity->REFTYPE);
            stmt.Bind(2, entity->REFID);
            stmt.Bind(3, entity->DESCRIPTION);
            stmt.Bind(4, entity->FILENAME);
            if (entity->id() > 0)
                stmt.Bind(5, entity->ATTACHMENTID);

            //wxLogDebug(stmt.GetSQL());
            stmt.ExecuteUpdate();
            stmt.Finalize();

            if (entity->id() > 0)
            {
                Cache c;
                for(Cache::iterator it = cache_.begin(); it != cache_.end(); ++ it)
                {
                    Self::Data* e = *it;
                    if (e->id() == entity->id() && e != entity) 
                        delete e;
                    else 
                        c.push_back(e);
                }
                cache_.clear();
                cache_.swap(c);
            }
        }
        catch(const wxSQLite3Exception &e) 
        { 
            wxLogError("ATTACHMENT_V1: Exception %s, %s", e.GetMessage().c_str(), entity->to_json());
            return false;
        }

        if (entity->id() <= 0) entity->id((db->GetLastRowId()).ToLong());
        return true;
    }

    /** Remove the Data record from the database and the memory table (cache) */
    bool remove(int id, wxSQLite3Database* db)
    {
        if (id <= 0) return false;
        try
        {
            wxString sql = "DELETE FROM ATTACHMENT_V1 WHERE ATTACHMENTID = ?";
            wxSQLite3Statement stmt = db->PrepareStatement(sql);
            stmt.Bind(1, id);
            //wxLogDebug(stmt.GetSQL());
            stmt.ExecuteUpdate();
            stmt.Finalize();

            Cache c;
            for(Cache::iterator it = cache_.begin(); it != cache_.end(); ++ it)
            {
                Self::Data* entity = *it;
                if (entity->id() == id) 
                    delete entity;
                else 
                    c.push_back(entity);
            }
            cache_.clear();
            cache_.swap(c);
        }
        catch(const wxSQLite3Exception &e) 
        { 
            wxLogError("ATTACHMENT_V1: Exception %s", e.GetMessage().c_str());
            return false;
        }

        return true;
    }

    /** Remove the Data record from the database and the memory table (cache) */
    bool remove(Self::Data* entity, wxSQLite3Database* db)
    {
        if (remove(entity->id(), db))
        {
            entity->id(-1);
            return true;
        }

        return false;
    }

    
    /**
    * Search the memory table (Cache) for the data record.
    * If not found in memory, search the database and update the cache.
    */
    Self::Data* get(int id, wxSQLite3Database* db)
    {
        if (id <= 0) 
        {
            ++ skip_;
            return 0;
        }
        for(Cache::reverse_iterator it = cache_.rbegin(); it != cache_.rend(); ++ it)
        {
            Self::Data* entity = *it;
            if (entity->id() == id) 
            {
                ++ hit_;
                return entity;
            }
        }
        
        ++ miss_;
        Self::Data* entity = 0;
        wxString where = wxString::Format(" WHERE %s = ?", PRIMARY::name().c_str());
        try
        {
            wxSQLite3Statement stmt = db->PrepareStatement(this->query() + where);
            stmt.Bind(1, id);

            //wxLogDebug(stmt.GetSQL());
            wxSQLite3ResultSet q = stmt.ExecuteQuery();
            if(q.NextRow())
            {
                entity = new Self::Data(q, this);
                cache_.push_back(entity);
            }
            stmt.Finalize();
        }
        catch(const wxSQLite3Exception &e) 
        { 
            wxLogError("%s: Exception %s", this->name().c_str(), e.GetMessage().c_str());
        }
        
        if (!entity) 
        {
            wxLogError("%s: %d not found", this->name().c_str(), id);
        }
 
        return entity;
    }

    /**
    * Return a list of Data records (Data_Set) derived directly from the database.
    * The Data_Set is sorted based on the column number.
    */
    Data_Set all(wxSQLite3Database* db, COLUMN col = COLUMN(0), bool asc = true)
    {
        Data_Set result;
        try
        {
            wxSQLite3ResultSet q = db->ExecuteQuery(col == COLUMN(0) ? this->query() : this->query() + " ORDER BY " + column_to_name(col) + " COLLATE NOCASE " + (asc ? " ASC " : " DESC "));

            //wxLogDebug(q.GetSQL());
            while(q.NextRow())
            {
                Self::Data entity(q, this);
                result.push_back(entity);
            }

            q.Finalize();
        }
        catch(const wxSQLite3Exception &e) 
        { 
            wxLogError("%s: Exception %s", this->name().c_str(), e.GetMessage().c_str());
        }

        return result;
    }
};
#endif //