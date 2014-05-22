open List;;
open String;;
let a1 = ref [] in
    let a2 = ref [] in
    let a3 = ref [] in
    try
      let a13 = ref (-1) in
      let a17 = ref "" in
      while true do
        a13 := !a13 + 1;
        let a4 = (read_line ()) in
        if (List.exists (fun a5 -> a5=a4) !a1) then
          ()
        else
          begin a1 := (String.copy a4) :: !a1 end;
        if (!a13 mod 2) = 0 then
          a17 := (String.copy a4)
        else
          (
            let a6 = !a17 in
            let a7 = ((String.copy a6), a4) in
            a2 := a7 :: !a2;
          )
      done;
    with _ ->
      a1 := List.sort
              (fun a8 a9 ->
               compare a8 a9)
              !a1;
      let a10 = ref true in
      while List.length !a1 > 0 && !a10 do
        let a11 = (
          let a12 = ref (-1) in
          let a13 = ref (-1) in
          while !a13 < (List.length !a1 - 1) do
            a13 := !a13 + 1;
            if !a12 = (-1) then (
              let a14 = (String.copy (List.nth !a1 !a13)) in
              let a15 = ref true in
              for j=0 to (List.length !a2 - 1) do
                if !a15 then (
                  let a17, a18 = List.nth !a2 j in
                  if a14 = a17 then
                    (a15 := false;)
                  else
                    ();
                )
              done;
              if !a15 then
                a12 := !a13;
              a15 := true;
            )
          done;
          if !a12 = (-1) then
            ""
          else
            String.copy (List.nth !a1 !a12);
        ) in
        if a11 = "" then a10 := false else
          (let a16 = ref [] in
           for a13=0 to (List.length !a2 - 1) do
             let a17, a18 = List.nth !a2 a13 in
             if a11 = a18 then () else
               a16 := (a17, a18) :: !a16
           done;
           a2 := !a16;
           a3 := a11 :: !a3;
           let newTasks = ref [] in
           for a13=0 to (List.length !a1 - 1) do
             let a14 = (String.copy (List.nth !a1 a13)) in
             if a11 = a14 then () else
               newTasks := !newTasks @ [a14]
           done;
           a1 := !newTasks;)
      done;
      a3 := List.rev !a3;
      if List.length !a2 > 0 then
        print_string ("cycle" ^ "\r")
      else
        List.iter (fun a12 -> (print_endline (a12 ^ "\r\n"))) !a3
