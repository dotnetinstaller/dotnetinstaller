<!-- tiscript, hyper text preprocessor mode  -->
<% var num_items = 1000; %>
<html>
<head>
<style> 

  html { background-color: #fff #e9e8f3 #e9e8f3 #fff; }

  table 
  { 
    border:1px solid #bdbccc; 
    overflow: auto;
    width:100%%;
    height:100%%;
    behavior:grid;
  }
  table th 
  { 
    color: white;
    font-family:"Century Gothic","Verdana"; 
	  font-size:10pt; 
    border:none;
    padding:4px; 
    background-color:#DDD; 
  }
  table th:hover 
  { 
    color: #ffe598;
  }
  
 
  table tr:current /* current row */ 
  { 
    background-color:#bdbccc; 
    color:white;
  } 
  
  table td 
  { 
    padding:2px; 
    font-family:"Verdana"; 
    font-size:9pt;  
  }
  
  table td:nth-child(1) { font-weight:bold; text-align:center; width:10%%; } /* first column */
  table td:nth-child(2) { border-left:1px solid #bdbccc; color:#8380A0; width:10%%; } /* second column */
  table td:nth-child(3) /* last column */
  { 
     text-align:left;
     overflow:hidden;        /* three line below - ellipsis */
     text-overflow:ellipsis;
     white-space:nowrap;
     width:80%;
     border-left:1px solid #bdbccc;
  } 
    
</style>

</head>
<body>
  Here is &lt;table&gt; with <% =num_items %> rows.
 <table border=1 width=100%>
  <% for(var i = 0; i < num_items; ++i ) { %>
  <tr>
  <td >row #<% =i %></td>
  <td >sample text 1</td>
  <td >sample text 2 and text 3</td>
  </tr>
<% } %>
  </select>
</body>
</html>