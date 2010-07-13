<!-- tiscript hyper text preprocessor   -->
<% var num_items = 10000; 
   var num_items2 = 1000; 
%>
<html>
<body>
  Here is &lt;select&gt; with <% =num_items %> items: 
 <select size=10>
  <% for(var i = 0; i < num_items; ++i ) { %>
  <option value="<% =i %>">item #<% =i %></option>
<% } %>
  </select>
  &lt;select&gt; with <% =num_items2 %> options-tables: 
 <select size=10>
  <% for(var i = 0; i < num_items2; ++i ) { %>
  <option value="<% =i %>">
  <table border=1>
    <tr><td>item #</td><td><% =i %></td></tr>
	<tr><td colspan=2>spanned cell</td></tr>
  </table>
  </option>
<% } %>
  </select>
  
  
</body>
</html>